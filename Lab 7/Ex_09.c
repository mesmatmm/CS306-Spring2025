// retrieve value from Thread function

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h> // For exit()

// Global variable (shared between threads):
int i = 2;

/**
 * Thread function that modifies a global variable and returns its address.
 * @param p Pointer to an integer passed from the main thread.
 * @return void* (Pointer to the modified global variable `i`).
 */
void *foo(void *p)
{
    // Print the value received from the main thread:
    printf("Value received as argument in starting routine: ");
    printf("%i\n", *(int *)p);

    // Modify the global variable:
    i = i * 10;

    // Return the address of the modified global variable:
    pthread_exit(&i);
}

int main(void)
{
    // Thread identifier:
    pthread_t id;

    // Local variable passed to the thread:
    int j = 1;

    // Create a new thread:
    if (pthread_create(&id, NULL, foo, &j) != 0)
    /* Error handling if thread creation fails */
    {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }

    // Pointer to store the returned value from the thread:
    int *ptr;

    // Wait for the thread to finish and get the returned value:
    if (pthread_join(id, (void **)&ptr) != 0) // Check pthread_join.md for more details
    /* Error handling if thread joining fails */
    {
        perror("Failed to join thread");
        exit(EXIT_FAILURE);
    }

    // Print the value received from the child thread:
    printf("Value received by parent from child: ");
    printf("%i\n", *ptr);

    return 0;
}
