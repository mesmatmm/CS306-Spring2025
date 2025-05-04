#include <pthread.h> // Include the pthread library
#include <stdio.h>   // Standard I/O library
#include <unistd.h>  // For sleep function

// Define a structure to hold multiple parameters
typedef struct
{
    int thread_id;     // Thread identifier
    char *thread_name; // Thread name
} ThreadData;

// Function to be executed by each thread
void *print_thread_info(void *arg)
{
    // Cast the argument to a ThreadData pointer
    ThreadData *data = (ThreadData *)arg;

    // Print the thread ID and name
    printf("Thread ID: %d, Thread Name: %s\n", data->thread_id, data->thread_name);

    // Simulate work
    //sleep(1); // Sleep for 1 second

    return NULL; // Return null when done
}

int main()
{
    pthread_t threads[3];      // Array to hold thread identifiers
    ThreadData thread_data[3]; // Array to hold thread data for each thread

    // Initialize thread data
    thread_data[0].thread_id = 1;
    thread_data[0].thread_name = "Alpha";

    thread_data[1].thread_id = 2;
    thread_data[1].thread_name = "Beta";

    thread_data[2].thread_id = 3;
    thread_data[2].thread_name = "Gamma";

    // Create the threads
    for (int i = 0; i < 3; i++)
    {
        if (pthread_create(&threads[i], NULL, print_thread_info, &thread_data[i]) != 0)
        {
            perror("Failed to create thread");
            return 1;
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < 3; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
            return 1;
        }
    }

    printf("Main thread: All tasks are complete.\n");

    return 0;
}
