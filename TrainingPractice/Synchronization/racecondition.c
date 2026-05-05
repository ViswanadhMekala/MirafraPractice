#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 1000000

int counter = 0; // Shared variable

// Thread 1: Incrementing
void* incrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        counter++; // Critical Section (Race Condition occurs here)
    }
    return NULL;
}

// Thread 2: Decrementing
void* decrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        counter--; // Critical Section (Race Condition occurs here)
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // Create the two threads
    pthread_create(&t1, NULL, incrementer, NULL);
    pthread_create(&t2, NULL, decrementer, NULL);

    // Wait for both to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Counter Value: %d\n", counter);
    printf("Expected Value: 0\n");

    return 0;
}

