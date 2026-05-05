#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/wait.h>

// Shared structure
struct SharedData {
    double n1, n2, result;
    char op;
    int ready; // Flag: 1 means data is ready for child
};

// Helper for Semaphore operations
void sem_op(int semid, int op) {
    struct sembuf s = {0, op, 0};
    semop(semid, &s, 1);
}

int main() {
    // 1. Create Shared Memory (shmget)
    int shmid = shmget(IPC_PRIVATE, sizeof(struct SharedData), IPC_CREAT | 0666);
    struct SharedData *data = (struct SharedData *)shmat(shmid, NULL, 0);

    // 2. Create Semaphore for synchronization (semget)
    int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0666);
    semctl(semid, 0, SETVAL, 1); // Initialize to 1 (unlocked)

    if (fork() == 0) { // CHILD: CALCULATOR
        while (1) {
            sem_op(semid, -1); // Lock
            if (data->ready == 1) {
                if (data->op == 'q') exit(0); // Quit condition
                
                if (data->op == '+') data->result = data->n1 + data->n2;
                else if (data->op == '-') data->result = data->n1 - data->n2;
                
                data->ready = 0; // Reset flag
                printf("[Child] Result %.2f written to memory.\n", data->result);
            }
            sem_op(semid, 1); // Unlock
            usleep(100000); // Sleep 100ms to avoid CPU hogging
        }
    } else { // PARENT: USER INTERFACE
        printf("[Parent] Enter num1 num2 op (or 0 0 q to quit): ");
        
        sem_op(semid, -1); // Lock
        scanf("%lf %lf %c", &data->n1, &data->n2, &data->op);
        data->ready = 1;
        sem_op(semid, 1); // Unlock

        // Wait for child to finish calculation
        while (1) {
            sem_op(semid, -1);
            if (data->ready == 0) {
                printf("[Parent] The result is: %.2f\n", data->result);
                sem_op(semid, 1);
                break;
            }
            sem_op(semid, 1);
        }

        wait(NULL);
        shmdt(data); // Detach
        shmctl(shmid, IPC_RMID, NULL); // Destroy memory
        semctl(semid, 0, IPC_RMID);    // Destroy semaphore
    }
    return 0;
}

