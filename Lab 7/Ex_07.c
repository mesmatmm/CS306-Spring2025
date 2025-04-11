// passing multiple values

#include <pthread.h> // Include the pthread library
#include <stdio.h>   // Standard I/O library
#include <unistd.h>  // For sleep function

// Define a structure to hold multiple parameters
typedef struct
{
    int start;     // Start number
    int end;       // End number
    char *message; // Message to print
} ThreadData;

// Function to be executed by the thread
void *print_numbers_with_message(void *arg)
{
    // Cast the argument to a ThreadData pointer
    ThreadData *data = (ThreadData *)arg;

    // Print the numbers from start to end with a message
    for (int i = data->start; i <= data->end; i++)
    {
        printf("Thread ID: %lu message: %s %d\n", (unsigned long)pthread_self(), data->message, i);
        sleep(1); // Sleep for 1 second to simulate work
    }

    return NULL; // Return null when done
}

int main()
{
    pthread_t thread_id; // Declare a thread identifier

    // Initialize the thread data
    ThreadData data;
    data.start = 1;
    data.end = 5;
    data.message = "Welcome";

    // Create the thread
    if (pthread_create(&thread_id, NULL, print_numbers_with_message, &data) != 0)
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
