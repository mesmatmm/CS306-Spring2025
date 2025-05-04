// Semaphore: Example 2

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // For sleep function

#define THREAD_COUNT 5
// sem_t semaphore;
void *thread_function(void *arg)
{
    int id = *(int *)arg;
    // sem_wait(&semaphore); // Decrement the semaphore
    printf("Thread %d is accessing the resource\n", id);
    sleep(1); // Simulate work
    printf("Thread %d is releasing the resource\n", id);
    // sem_post(&semaphore); // Increment the semaphore
    return NULL;
}
int main()
{
    pthread_t threads[THREAD_COUNT];
    int thread_ids[THREAD_COUNT];
    // sem_init(&semaphore, 0, 2); // Initialize semaphore with a value of 2
    //  Create threads
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }
    // Wait for threads to finish
    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(threads[i], NULL);
    }
    // sem_destroy(&semaphore); // Destroy the semaphore
    return 0;
}

/*
Explanation:
- The semaphore is initialized with a value of 2, meaning only 2
threads can access the resource at a time.
- sem_wait(&semaphore) decrements the semaphore, and if the value is 0, the thread waits.
- sem_post(&semaphore) increments the semaphore, allowing another thread to access the resource.

*/