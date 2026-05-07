#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

pid_t child_pid = -1;
FILE *log_fp = NULL;

// Helper to get current timestamp string
const char* get_timestamp() {
    static char buffer[26];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    return buffer;
}

// Signal handler for Ctrl+C
void handle_sigint(int sig) {
    if (child_pid > 0) {
        printf("\n[%s] [Supervisor] Shutting down. Terminating worker (PID %d)...\n", get_timestamp(), child_pid);
        if (log_fp) fprintf(log_fp, "[%s] [Supervisor] Shutdown initiated. Killing PID %d\n", get_timestamp(), child_pid);
        
        kill(child_pid, SIGTERM);
        waitpid(child_pid, NULL, 0);
    }
    if (log_fp) fclose(log_fp);
    exit(0);
}

void workerFunction(char *command, char *args[]) {
    int pipe_fd[2];
    char buffer[256];

    log_fp = fopen("supervisor.log", "a");
    if (!log_fp) {
        perror("Could not open log file");
        exit(1);
    }

    while (1) {
        if (pipe(pipe_fd) == -1) {
            perror("Pipe failed");
            exit(1);
        }

        child_pid = fork();

        if (child_pid == 0) { // Child Process
            close(pipe_fd[0]); 
            dup2(pipe_fd[1], STDOUT_FILENO);
            dup2(pipe_fd[1], STDERR_FILENO);
            close(pipe_fd[1]);

            execvp(command, args);
            perror("Exec failed");
            exit(1);
        } 
        else if (child_pid > 0) { // Parent Process
            close(pipe_fd[1]); 

            printf("[%s] [Supervisor] Started worker PID %d\n", get_timestamp(), child_pid);
            fprintf(log_fp, "[%s] Started: %s (PID %d)\n", get_timestamp(), command, child_pid);
            fflush(log_fp);

            ssize_t bytes_read;
            while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer) - 1)) > 0) {
                buffer[bytes_read] = '\0';
                
                // Terminal Output
                printf("[Worker]: %s", buffer);
                
                // File Log Output
                fprintf(log_fp, "[Worker]: %s", buffer);
                fflush(log_fp);
            }
            close(pipe_fd[0]);

            int status;
            waitpid(child_pid, &status, 0);

            // Crash & Exit Analysis
            if (WIFEXITED(status)) {
                int code = WEXITSTATUS(status);
                fprintf(log_fp, "[%s] Worker %d finished with code %d\n", get_timestamp(), child_pid, code);
            } 
            else if (WIFSIGNALED(status)) {
                int sig = WTERMSIG(status);
                fprintf(log_fp, "[%s] ALERT: Worker %d crashed (Signal %d: %s)\n", 
                        get_timestamp(), child_pid, sig, strsignal(sig));
            }

            printf("[%s] [Supervisor] Worker stopped. Restarting in 1s...\n", get_timestamp());
            child_pid = -1;
            sleep(1);
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [args...]\n", argv[0]);
        return 1;
    }

    struct sigaction sa;
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    workerFunction(argv[1], &argv[1]);
    return 0;
}

