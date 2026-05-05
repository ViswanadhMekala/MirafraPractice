#include <stdio.h>
#include <pthread.h>
#include <stdatomic.h> // 1. Include the atomic header

#define ITERATIONS 1000000

// 2. Define the variable as an atomic type
atomic_int counter = 0; 

void* incrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        // 3. Atomic increment (Thread-safe by default)
        atomic_fetch_add(&counter, 1);
    }
    return NULL;
}

void* decrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        // 4. Atomic decrement (Thread-safe by default)
        atomic_fetch_sub(&counter, 1);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    pthread_create(&t1, NULL, incrementer, NULL);
    pthread_create(&t2, NULL, decrementer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Counter Value: %d\n", counter);
    printf("Expected Value: 0\n");

    return 0;
}

