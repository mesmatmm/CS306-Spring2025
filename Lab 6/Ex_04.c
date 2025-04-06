/*
COMPILE: gcc -pthread Ex_02.c
RUN: a.exe
*/

/*
 * File: multi_thread_no_args.c
 * Description: Creates 5 threads without passing any arguments. Each thread prints
 *              a message. The main thread
 *              waits for all threads to finish before printing its own message.
 */

#include <pthread.h> // For thread management
#include <stdio.h>   // For I/O operations
#include <stdlib.h>  // For exit()

// Function executed by each thread
// arg: Unused (no arguments passed)
// Returns: NULL
void *thread_function(void *arg)
{
    printf("Hello from thread! Thread ID: %lu \n", (unsigned long)pthread_self());
    return NULL; // Indicate successful completion
}

// Main function: Creates 5 threads, waits for them, and prints a message
// Returns: 0 on success
int main()
{
    pthread_t threads[5]; // Array to store thread IDs

    // Create 5 threads
    for (int i = 0; i < 5; i++)
    {
        if (pthread_create(&threads[i], NULL, thread_function, NULL) != 0)
        /* used for error handling when creating a thread */
        {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all 5 threads to finish
    for (int i = 0; i < 5; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        /* used for error handling when waiting a thread */
        {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    // Print message from the main thread
    printf("Main thread finished.\n");

    return 0; // Program ends successfully
}