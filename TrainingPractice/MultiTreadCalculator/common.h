#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <semaphore.h>

#define SHM_SIZE 1024
#define MSG_KEY 1234
#define SHM_KEY 5678

typedef struct {
    long msg_type;     // 1 for request
    char expr[256];
} msg_packet;

typedef struct {
    double result;
    sem_t sync_sem;    // Semaphore for data readiness
} shared_data;

