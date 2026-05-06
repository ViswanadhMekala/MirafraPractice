#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>   // Added for timer
#include <errno.h>  // Added for error checking
#include "common.h" 

int main() {
    // 1. Get access to the Message Queue
    int msqid = msgget(MSG_KEY, 0666);
    if (msqid == -1) {
        perror("msgget failed (Is the server running?)");
        exit(1);
    }

    // 2. Get access to the Shared Memory
    int shmid = shmget(SHM_KEY, sizeof(shared_data), 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }
    shared_data* data = (shared_data*)shmat(shmid, NULL, 0);

    // 3. Prepare the message
    msg_packet msg;
    msg.msg_type = 1;
    
    printf("Enter a simple math expression (e.g., 5+5): ");
    scanf("%19s", msg.expr); 

    // 4. Send to Server via Message Queue
    if (msgsnd(msqid, &msg, sizeof(msg.expr), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }

    // 5. Setup Timeout (5 seconds from now)
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) == -1) {
        perror("clock_gettime");
        exit(1);
    }
    ts.tv_sec += 5; // 5-second deadline

    printf("Waiting for server response...\n");

    // 6. Timed wait for the Semaphore
    if (sem_timedwait(&data->sync_sem, &ts) == -1) {
        if (errno == ETIMEDOUT) {
            printf("\n[TIMEOUT] The server did not respond within 5 seconds.\n");
            printf("Check if the server is running or if the expression was valid.\n");
        } else {
            perror("sem_timedwait failed");
        }
    } else {
        // Success! Read the result from Shared Memory
        printf("Result from Shared Memory: %f\n", data->result);
    }

    // Clean up
    shmdt(data);
    return 0;
}

