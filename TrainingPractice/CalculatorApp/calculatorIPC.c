#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Structure to pass all data at once
struct Calculation {
    double num1;
    double num2;
    char op;
};

int main() {
    int fd[2]; // fd[0] is read end, fd[1] is write end
    pid_t pid;

    // 1. Create the pipe before forking
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) { // Parent Process: User Input
        close(fd[0]); // Close unused read end

        struct Calculation calc;
        printf("[Parent] Enter first number: ");
        scanf("%lf", &calc.num1);
        printf("[Parent] Enter second number: ");
        scanf("%lf", &calc.num2);
        printf("[Parent] Enter operator (+, -, *, /): ");
        scanf(" %c", &calc.op);

        // Send the entire structure to the child process
        write(fd[1], &calc, sizeof(struct Calculation));
        close(fd[1]); // Close write end after sending
        
        wait(NULL); // Wait for child to finish calculation
    } 
    else { // Child Process: Calculator
        close(fd[1]); // Close unused write end

        struct Calculation received;
        // read() blocks until the parent writes data
        read(fd[0], &received, sizeof(struct Calculation));
        
        double result;
        int valid = 1;

        switch(received.op) {
            case '+': result = received.num1 + received.num2; break;
            case '-': result = received.num1 - received.num2; break;
            case '*': result = received.num1 * received.num2; break;
            case '/': 
                if(received.num2 != 0) result = received.num1 / received.num2; 
                else { printf("[Child] Error: Division by zero!\n"); valid = 0; }
                break;
            default: printf("[Child] Error: Invalid operator!\n"); valid = 0;
        }

        if (valid) {
            printf("[Child] Result: %.2f %c %.2f = %.2f\n", 
                   received.num1, received.op, received.num2, result);
        }

        close(fd[0]); // Close read end
        exit(0);
    }

    return 0;
}
