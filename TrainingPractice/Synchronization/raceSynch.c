#include <stdio.h>
#include <pthread.h>

#define ITERATIONS 1000000

int counter = 0;
// 1. Declare the Mutex
pthread_mutex_t lock;

void* incrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        // 2. Lock before entering the critical section
        pthread_mutex_lock(&lock);
        counter++; 
        // 3. Unlock after finished
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* decrementer(void* arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        pthread_mutex_lock(&lock);
        counter--; 
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    // 4. Initialize the Mutex
    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, incrementer, NULL);
    pthread_create(&t2, NULL, decrementer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // 5. Destroy the Mutex when done
    pthread_mutex_destroy(&lock);

    printf("Final Counter Value: %d\n", counter);
    printf("Expected Value: 0\n");

    return 0;
}

