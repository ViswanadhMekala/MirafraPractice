#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 1000000

int counter = 0;
// 1. Declare the spinlock
pthread_spinlock_t spinlock;

void* incrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        // 2. "Spin" until the lock is acquired
        pthread_spin_lock(&spinlock);
        counter++; 
        // 3. Release the lock
        pthread_spin_unlock(&spinlock);
    }
    return NULL;
}

void* decrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_spin_lock(&spinlock);
        counter--; 
        pthread_spin_unlock(&spinlock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // 4. Initialize the spinlock
    // PTHREAD_PROCESS_PRIVATE means it's for threads within this process
    pthread_spin_init(&spinlock, PTHREAD_PROCESS_PRIVATE);

    pthread_create(&t1, NULL, incrementer, NULL);
    pthread_create(&t2, NULL, decrementer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // 5. Clean up
    pthread_spin_destroy(&spinlock);

    printf("Final Counter Value: %d\n", counter);
    printf("Expected Value: 0\n");

    return 0;
}

