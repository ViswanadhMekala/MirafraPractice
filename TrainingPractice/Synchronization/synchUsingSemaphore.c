#include <stdio.h>
#include <pthread.h>
#include <semaphore.h> // 1. Include the semaphore header

#define ITERATIONS 1000000

int counter = 0;
sem_t mutex_sem; // 2. Declare the semaphore

void* incrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        sem_wait(&mutex_sem); // 3. P() operation: Wait/Decrement
        counter++; 
        sem_post(&mutex_sem); // 4. V() operation: Signal/Increment
    }
    return NULL;
}

void* decrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        sem_wait(&mutex_sem); // Lock critical section
        counter--; 
        sem_post(&mutex_sem); // Unlock critical section
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // 5. Initialize: (semaphore, pshared=0 for threads, initial_value=1)
    sem_init(&mutex_sem, 0, 1); 

    pthread_create(&t1, NULL, incrementer, NULL);
    pthread_create(&t2, NULL, decrementer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // 6. Clean up
    sem_destroy(&mutex_sem);

    printf("Final Counter Value: %d\n", counter);
    printf("Expected Value: 0\n");

    return 0;
}

