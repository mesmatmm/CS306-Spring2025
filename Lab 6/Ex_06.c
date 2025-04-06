/*
create one thread
passing paramter to the load function
using sleep function
*/

#include <pthread.h> // Include the pthread library
#include <stdio.h>   // Standard I/O library
#include <unistd.h>  // For sleep function

// Function to be executed by the thread
void *print_numbers(void *arg)
{
    int *n = (int *)arg; // Cast the argument to an integer pointer
    for (int i = 1; i <= *n; i++)
    {
        printf("Thread: %d\n", i);
        //sleep(1); // Sleep for 1 second to simulate work
    }
    return NULL; // Return null when done
}

int main()
{
    pthread_t thread_id; // Declare a thread identifier
    int num = 5;         // Number of iterations for the thread to print

    // Create the thread
    if (pthread_create(&thread_id, NULL, print_numbers, &num) != 0)
    {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for the thread to complete
    if (pthread_join(thread_id, NULL) != 0)
    {
        perror("Failed to join thread");
        return 1;
    }

    printf("Main thread: All tasks are complete.\n");

    return 0;
}
