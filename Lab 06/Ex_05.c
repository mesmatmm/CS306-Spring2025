/*
 * File: multi_thread.c
 * Description: 
 * Creates 5 threads, each printing a message. 
 * passing a value to the load function
 * The main thread waits
 * for all threads to finish before printing its own message.
 */

#include <pthread.h> // For thread management
#include <stdio.h>   // For I/O operations
#include <stdlib.h>  // For exit()

// Function executed by each thread
// arg: Pointer to the thread's unique ID (cast to int)
// Returns: NULL
void *thread_function(void *arg)
{
    int thread_index = *(int *)arg;                  // Cast and dereference the argument to get the thread ID
    printf("Hello from thread %d!\n", thread_index); // Print message with thread ID
    return NULL;                                     // Indicate successful completion
}

// Main function: Creates 5 threads, waits for them, and prints a message
// Returns: 0 on success
int main()
{
    pthread_t threads[5]; // Array to store thread IDs
    int thread_index[5];  // Array to store thread index

    // Create 5 threads
    for (int i = 0; i < 5; i++)
    {
        thread_index[i] = i + 1; // Assign thread ID (1 to 5)
        // Create a thread and pass the address of thread_args[i] as the argument
        if (pthread_create(&threads[i], NULL, thread_function, &thread_index[i]) != 0)
        {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all 5 threads to finish
    for (int i = 0; i < 5; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    // Print message from the main thread
    printf("Main thread finished.\n");

    return 0; // Program ends successfully
}