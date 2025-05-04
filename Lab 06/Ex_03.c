/* Create 3 Threads
    pthread_self() used to get thread id to identify each thread
 * File: multi_thread_no_args.c
 * Description: Creates 3 threads without passing any arguments. Each thread prints
 *              a message with its logical ID (based on loop counter). The main thread
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
    // Get the thread ID of the current thread
    pthread_t tid = pthread_self();
    printf("Hello from thread! Thread ID: %lu \n", (unsigned long)tid);
    return NULL; // Indicate successful completion
}

// Main function: Creates 5 threads, waits for them, and prints a message
// Returns: 0 on success
int main()
{
    pthread_t thread1, thread2, thread3; // to store thread IDs

    // Create 5 threads
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    pthread_create(&thread3, NULL, thread_function, NULL);

    // Wait for all 5 threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    // Print message from the main thread
    printf("Main thread finished.\n");

    return 0; // Program ends successfully
}