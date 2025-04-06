/* More than one thread
 * File: Ex_02.c
 * Description: This program demonstrates the basic usage of POSIX threads (pthreads) in C.
 *              It creates a new thread that prints a message, and the main thread waits
 *              for the newly created thread to finish before printing its own message.
 *              The program illustrates thread creation, thread execution, and thread joining.
 */

#include <pthread.h> // Include the pthread library for thread management
#include <stdio.h>   // Include the standard I/O library for input/output operations

// Function: thread_function
// Description: This function is executed by the new thread when it starts.
//              It prints a message to the console and then exits.
// Parameters:
//   - arg: A pointer to the argument passed to the thread (unused in this example).
// Returns: NULL, as the function does not need to return any value.
void *thread_function(void *arg)
{
    printf("Hello from thread!\n"); // Print a message from the new thread
    return NULL;                    // Return NULL to indicate successful completion
}

int main()
{
    pthread_t thread1, thread2; // two thread identifiers

    // creat two threads
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    // wait for the threads to finish their work
    pthread_join(thread1, NULL);
    pthread_join(thread1, NULL);

    // Print a message from the main thread after the new thread has finished
    printf("Main thread finished.\n");

    return 0; // Return 0 to indicate successful program termination
}