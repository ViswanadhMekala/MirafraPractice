#include "common.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>

// 1. Move IDs to global scope so handle_sigint can access them
int msqid;
int shmid;

void handle_sigint(int sig) {
    printf("\nShutting down server safely...\n");
    // Clean up IPC resources from the kernel
    msgctl(msqid, IPC_RMID, NULL); 
    shmctl(shmid, IPC_RMID, NULL);
    exit(0);
}

void* worker_thread(void* arg) {
    msg_packet* msg = (msg_packet*)arg;
    double num1, num2, res = 0;
    char op;

    printf("Processing expression: %s\n", msg->expr);

    // Parse the string sent by the client
    int parsed = sscanf(msg->expr, "%lf %c %lf", &num1, &op, &num2);

    if (parsed == 3) {
        switch (op) {
            case '+': res = num1 + num2; break;
            case '-': res = num1 - num2; break;
            case '*': res = num1 * num2; break;
            case '/': 
                if (num2 != 0) res = num1 / num2; 
                else printf("Error: Division by zero\n");
                break;
            default: printf("Error: Unknown operator %c\n", op);
        }
    } else {
        printf("Error: Invalid expression format: %s\n", msg->expr);
    }

    // Attach to Shared Memory (using the global shmid or looking it up)
    shared_data* data = (shared_data*)shmat(shmid, NULL, 0);
    if (data == (void*)-1) {
        perror("shmat failed in thread");
    } else {
        data->result = res; 
        sem_post(&data->sync_sem); // Signal client data is ready
        shmdt(data);
    }

    free(msg); // Clean up the malloc'd message
    return NULL;
}

int main() {
    // 2. Register the handler BEFORE creating IPCs
    signal(SIGINT, handle_sigint); 

    // 3. Initialize Global IDs (Note: no 'int' before names here)
    msqid = msgget(MSG_KEY, 0666 | IPC_CREAT);
    shmid = shmget(SHM_KEY, sizeof(shared_data), 0666 | IPC_CREAT);
    
    if (msqid == -1 || shmid == -1) {
        perror("Failed to create IPC structures");
        exit(1);
    }

    shared_data* data = (shared_data*)shmat(shmid, NULL, 0);
    sem_init(&data->sync_sem, 1, 0); // Initialize semaphore (shared=1, value=0)
    shmdt(data);

    printf("Calculator Server Running... (Press Ctrl+C to quit)\n");

    while (1) {
        msg_packet* incoming = malloc(sizeof(msg_packet));
        
        // Receive message from queue
        if (msgrcv(msqid, incoming, sizeof(incoming->expr), 1, 0) != -1) {
            pthread_t tid;
            pthread_create(&tid, NULL, worker_thread, incoming);
            pthread_detach(tid);
        } else {
            free(incoming); // Clean up if msgrcv fails (e.g., on interrupt)
        }
    }
    return 0;
}

