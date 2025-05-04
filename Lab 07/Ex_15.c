// Semaphore: Example 1

#include <stdio.h>     // Standard I/O library for printf
#include <pthread.h>   // POSIX thread library for creating and managing threads
#include <semaphore.h> // Semaphore library for synchronizing threads
#include <unistd.h>    // For sleep function

#define NUM_THREADS 5 // Define the number of threads to create

int counter = 0; // Shared counter variable to be incremented by threads
sem_t semaphore; // Semaphore to control access to the shared counter
/*
- Semaphore is another synchronization mechanism that can be used to control access
to a resource. Unlike mutexes, semaphores can allow more than one thread to access
a resource concurrently, based on the semaphore's value.
- If the semaphore is initialized with a value of 1, which effectively makes it
 a binary semaphore (similar to a mutex).
- Semaphores: The semaphore is used to ensure that only one thread can increment
the counter at a time, providing mutual exclusion for the critical section (counter++).
This prevents race conditions where multiple threads try to update the counter
simultaneously.
*/
// Function executed by each thread
void *increment_counter(void *threadid)
{
    long tid = (long)threadid; // Cast the thread ID to a long
    printf("Thread %ld starting\n", tid);

    for (int i = 0; i < 1000; i++) // Each thread increments the counter 1000 times
    {
        sem_wait(&semaphore); // Wait (decrement) the semaphore to enter the critical section
        counter++;            // Increment the shared counter
        sem_post(&semaphore); // Signal (increment) the semaphore to leave the critical section
    }
    printf("Thread %ld done\n", tid); // Indicate that the thread is done
    pthread_exit(NULL); // Exit the thread
}

int main()
{
    pthread_t threads[NUM_THREADS]; // Array to hold thread identifiers
    sem_init(&semaphore, 0, 1);     // Initialize the semaphore with an initial value of 1
    /*
    First parameter: - Pointer to the semaphore variable to initialize
    Second parameter: - Indicates the sharing scope of the semaphore:
    0: The semaphore is local to the current process (shared only between threads of the same process).
    Non-zero (1 or another value): The semaphore is shared between multiple processes (must be placed in shared memory).
    Third parameter: - The initial value of the semaphore (here, it starts at 1, making it a binary semaphore for mutual exclusion).
    */

    // Create NUM_THREADS threads
    for (long t = 0; t < NUM_THREADS; t++)
    {
        pthread_create(&threads[t], NULL, increment_counter, (void *)t);
    }

    // Wait for all threads to complete
    for (int t = 0; t < NUM_THREADS; t++)
    {
        pthread_join(threads[t], NULL);
    }

    printf("Final counter value: %d\n", counter); // Print the final value of the counter

    sem_destroy(&semaphore); // Destroy the semaphore to free resources
    return 0;
}
