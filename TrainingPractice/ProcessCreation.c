#include <stdio.h>

#include <unistd.h>

#include <sys/types.h>

#include <sys/wait.h>
 
int main() {

    pid_t pid;
 
    pid = fork();  // Create child process
 
    if (pid < 0) {

        // Fork failed

        perror("fork failed");

        return 1;

    }

    else if (pid == 0) {

        // Child process

        printf("Child Process: PID = %d\n", getpid());
 
        // Replace child with 'ls -l'

        execl("/bin/ls", "ls", "-l", NULL);
 
        // If exec fails

        perror("exec failed");

    }

    else {

        // Parent process

        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
 
        // Wait for child to complete

        wait(NULL);
 
        printf("Child finished execution\n");

    }
 
    return 0;

}
 
