//  Passing & Retrieving Multiple Values via Struct
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Struct to hold input and output data
typedef struct
{
    int number;       // Input value
    int squared;      // Output: number²
    int cubed;        // Output: number³
    char message[50]; // Output: Modified message
} ThreadData;

// Thread function: computes square, cube, and modifies message
void *compute_values(void *arg)
{
    ThreadData *data = (ThreadData *)arg;

    // Compute square and cube
    data->squared = data->number * data->number;
    data->cubed = data->number * data->number * data->number;

    // Modify the message using (snprintf)
    // Safe & formatted // Ensure null-termination
    snprintf(data->message, sizeof(data->message),
             "Thread modifidded this! (Original: %d)",
             data->number);

    // Return the modified struct (as a void pointer)
    pthread_exit((void *)data);
}

int main()
{
    pthread_t thread_id;
    ThreadData data = {
        .number = 3,  // Input value
        .squared = 0, // Will be updated by thread
        .cubed = 0,   // Will be updated by thread
        .message = "Initial message"};

    // Create thread and pass the struct
    if (pthread_create(&thread_id, NULL, compute_values, &data) != 0)
    {
        perror("Failed to create thread");
        return 1;
    }

    // Pointer to receive the returned struct
    ThreadData *result;

    // Wait for thread and get the modified struct
    if (pthread_join(thread_id, (void **)&result) != 0)
    {
        perror("Failed to join thread");
        return 1;
    }

    // Print the results
    printf("Original number: %d\n", result->number);
    printf("Squared: %d\n", result->squared);
    printf("Cubed: %d\n", result->cubed);
    printf("Message: %s\n", result->message);

    return 0;
}