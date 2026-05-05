#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/wait.h>

// 1. Define the message structure
struct msg_buffer {
    long msg_type; // Mandatory: used to route messages
    double n1, n2;
    char op;
    double result;
};

int main() {
    // Generate a unique key for the queue
    key_t key = ftok("progfile", 65);
    // Create the queue (IPC_CREAT) with permissions (0666)
    int msgid = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0) { // CHILD PROCESS (The Calculator)
        struct msg_buffer msg;

        // Receive message of type 1 (Request)
        // msgrcv(id, buffer, size_excluding_type, type, flags)
        msgrcv(msgid, &msg, sizeof(msg) - sizeof(long), 1, 0);

        printf("[Child] Calculating...\n");
        if (msg.op == '+') msg.result = msg.n1 + msg.n2;
        else if (msg.op == '-') msg.result = msg.n1 - msg.n2;
        else if (msg.op == '*') msg.result = msg.n1 * msg.n2;
        else if (msg.op == '/') msg.result = (msg.n2 != 0) ? msg.n1 / msg.n2 : 0;

        // Change type to 2 to send it back to Parent
        msg.msg_type = 2;
        msgsnd(msgid, &msg, sizeof(msg) - sizeof(long), 0);
        exit(0);
    } 
    else { // PARENT PROCESS (The User Interface)
        struct msg_buffer msg;
        msg.msg_type = 1; // Type 1 = Requests to child

        printf("[Parent] Enter calculation (num1 num2 op): ");
        scanf("%lf %lf %c", &msg.n1, &msg.n2, &msg.op);

        // Send request to queue
        msgsnd(msgid, &msg, sizeof(msg) - sizeof(long), 0);

        // Wait for type 2 (Result) from child
        msgrcv(msgid, &msg, sizeof(msg) - sizeof(long), 2, 0);

        printf("[Parent] Result received from Queue: %.2f\n", msg.result);

        // Clean up: Destroy the message queue
        wait(NULL);
        msgctl(msgid, IPC_RMID, NULL);
    }

    return 0;
}

