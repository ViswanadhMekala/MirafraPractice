#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2]; // Pipe 1: Parent -> Child 1
    int fd2[2]; // Pipe 2: Child 1 -> Child 2

    pipe(fd1);
    pipe(fd2);

    if (fork() == 0) { // CHILD 1: CALCULATOR
        close(fd1[1]); close(fd2[0]); // Close unused ends
        
        int a, b;
        read(fd1[0], &a, sizeof(int));
        read(fd1[0], &b, sizeof(int));
        
        int sum = a + b;
        printf("[Child 1] Calculated %d + %d = %d. Sending to Child 2...\n", a, b, sum);
        
        write(fd2[1], &sum, sizeof(int)); // Send result to Child 2
        
        close(fd1[0]); close(fd2[1]);
        exit(0);
    }

    if (fork() == 0) { // CHILD 2: PRINTER
        close(fd1[0]); close(fd1[1]); close(fd2[1]); // Close all but Pipe 2 read
        
        int final_res;
        read(fd2[0], &final_res, sizeof(int));
        printf("[Child 2] FINAL RESULT RECEIVED: *** %d ***\n", final_res);
        
        close(fd2[0]);
        exit(0);
    }

    // PARENT PROCESS
    close(fd1[0]); close(fd2[0]); close(fd2[1]); // Close ends Parent doesn't use
    
    int val1, val2;
    printf("[Parent] Enter two numbers: ");
    scanf("%d %d", &val1, &val2);
    
    write(fd1[1], &val1, sizeof(int));
    write(fd1[1], &val2, sizeof(int));
    
    close(fd1[1]);
    
    wait(NULL); // Wait for Child 1
    wait(NULL); // Wait for Child 2
    return 0;
}

