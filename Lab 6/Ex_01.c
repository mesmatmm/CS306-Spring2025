/*
 * File: Ex_01.c
 * Description: This program demonstrates the basic usage of POSIX threads (pthreads) in C.
 *              It creates a new thread that prints a message, and the main thread waits
 *              for the newly created thread to finish before printing its own message.
 *              The program illustrates thread creation, thread execution, and thread joining.
 */

#include <pthread.h>  // Include the pthread library for thread management
#include <stdio.h>    // Include the standard I/O library for input/output operations

// Function: thread_function
// Description: This function is executed by the new thread when it starts.
//              It prints a message to the console and then exits.
// Parameters:
//   - arg: A pointer to the argument passed to the thread (unused in this example).
// Returns: NULL, as the function does not need to return any value.
void* thread_function(void* arg) {
    printf("Hello from thread!\n");  // Print a message from the new thread
    return NULL;  // Return NULL to indicate successful completion
}

// Function: main
// Description: The main function of the program. It creates a new thread, waits for it
//              to finish, and then prints a message from the main thread.
// Returns: 0 to indicate successful program termination.
int main() {
    pthread_t thread_id;  // Declare a variable to store the thread ID

    // Create a new thread
    // Parameters:
    //   - &thread_id: Pointer to the thread ID variable where the ID of the new thread will be stored.
    //   - NULL: Use default thread attributes.
    //   - thread_function: The function that the new thread will execute.
    //   - NULL: No argument is passed to the thread function.
    pthread_create(&thread_id, NULL, thread_function, NULL);

    // Wait for the newly created thread to finish execution
    // Parameters:
    //   - thread_id: The ID of the thread to wait for.
    //   - NULL: No return value is expected from the thread.
    pthread_join(thread_id, NULL);

    // Print a message from the main thread after the new thread has finished
    printf("Main thread finished.\n");

    return 0;  // Return 0 to indicate successful program termination
}