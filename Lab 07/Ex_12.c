// using MUTEX
// Multiple threads accessing shared memory location
// With syrchronization to prevent
// race condition

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> // For exit()

int shared_data = 0;   // Shared resource
pthread_mutex_t mutex; // Mutex to protect shared_data
void *increment(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        pthread_mutex_lock(&mutex);   // Lock the mutex
        shared_data++;                // Access the shared resource
        pthread_mutex_unlock(&mutex); // Unlock the mutex
    }
    return NULL;
}
int main()
{
    int num_threads = 5;
    pthread_t threads[5];             // Array to store thread IDs
    pthread_mutex_init(&mutex, NULL); // Initialize the mutex

    // Create threads
    for (int i = 0; i < num_threads; i++)
    {
        if (pthread_create(&threads[i], NULL, increment, NULL) != 0)
        {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    printf("Final value of shared_data: %d\n", shared_data);

    pthread_mutex_destroy(&mutex);
    return 0;
}