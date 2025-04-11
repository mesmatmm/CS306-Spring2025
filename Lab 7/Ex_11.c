// Multiple threads accessing shared memory location
// Without any syrchronization
/*
A race condition occurs when two threads try to modify a shared variable
 without synchronization, leading to unpredictable results.
 However, race conditions are not guaranteed to happen every
  time—they depend on how threads are scheduled by the OS.
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> // For exit()

int shared_data = 0; // Shared resource

void *increment(void *arg)
{
    for (int i = 0; i < 100000; i++)
    {
        shared_data++; // Access the shared resource
        // shared_data = shared_data + 1;
    }
    return NULL;
}

int main()
{
    int num_threads = 5;
    pthread_t threads[5]; // Array to store thread IDs

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
    return 0;
}