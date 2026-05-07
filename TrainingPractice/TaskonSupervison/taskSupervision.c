#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

pid_t child_pid = -1;

// signal handler to catch ctrl+c (SIGINT)

void handle_sigint(int sig){
  if(child_pid > 0){
    printf("\n[Supervisor] Shutting down. Terminating worker (PID %d)...\n",child_pid);
    kill(child_pid,SIGTERM); // Gracefully tell the child to stop
    waitpid(child_pid,NULL,0); // Cleanup the zombie
  }
  exit(0);
}

void workerFunction(char *command, char *args[]){
    int pipe_fd[2];
    char buffer[256];
    
    while(1){
      if(pipe(pipe_fd) == -1){
        perror("pipe failed");
        exit(1);
      }
      
      child_pid = fork();
      
      if(child_pid == 0){ // child process
        close(pipe_fd[0]); // Close unused read end
        dup2(pipe_fd[1],STDOUT_FILENO);
        dup2(pipe_fd[1],STDERR_FILENO);
        close(pipe_fd[1]);
        
        execvp(command,args);
        perror("Exec failed");
        exit(1);
      }
      else if(child_pid > 0){// parent process
        close(pipe_fd[1]);  // close unused write end
        
        printf("[Supervisor] Worker started withPID %d\n", child_pid);
        
        ssize_t bytes_read;
        // read untill pipe is closed (worker exits)
        while((bytes_read = read(pipe_fd[0],buffer,sizeof(buffer) -1)) > 0){
          buffer[bytes_read] = '\0';
          printf("[Worker]: %s", buffer);
        }
        close(pipe_fd[0]);
        
        int status;
        waitpid(child_pid,&status,0);
        
        if (WIFEXITED(status)) {
            // Child finished normally (e.g., exit(0) or return 0)
            int exit_code = WEXITSTATUS(status);
            printf("[Supervisor] Worker (PID %d) finished with exit code %d\n", child_pid, exit_code);
        } 
        else if (WIFSIGNALED(status)) {
            // Child crashed or was killed by a signal
            int sig_num = WTERMSIG(status);
            printf("[Supervisor] ALERT: Worker (PID %d) crashed! Signal: %d (%s)\n", 
                    child_pid, sig_num, strsignal(sig_num));
        }

        printf("[Supervisor] Worker (PID %d) stopped. Restarting...\n", child_pid);
        child_pid = -1; // reset before sleep/restart
        sleep(1);
      }
    }
}

int main(int argc, char* argv[]){
  if(argc < 2){
      fprintf(stderr,"Usage: %s <command> [args...]\n",argv[0]);
      return 1;  
  }
  else{
      struct sigaction sa;
      sa.sa_handler = handle_sigint;
      sigemptyset(&sa.sa_mask);
      sa.sa_flags = 0;
      sigaction(SIGINT, &sa, NULL);
      workerFunction(argv[1],&argv[1]);
      return 0;
  }
}
