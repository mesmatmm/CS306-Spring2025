#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // For sleep function

#define BUFFER_SIZE 5 // Define the size of the buffer
#define MAX_ITEMS 100   // Define the maximum number of items to be produced/consumed

// Shared buffer and associated indices
int buffer[BUFFER_SIZE];
int in = 0;      // Index for the next item to produce
int out = 0;     // Index for the next item to consume
int counter = 0; // number of items in the buffer

// Counters for produced and consumed items
int produced_count = 0;
int consumed_count = 0;

// Synchronization variables
pthread_mutex_t mutex; // Mutex to protect shared data
pthread_cond_t full;   // Condition variable to signal when the buffer has items
pthread_cond_t empty;  // Condition variable to signal when the buffer has space

// Producer thread function
void *producer(void *arg)
{
    int item = 1; // Start with item 1 and increment for each produced item

    while (produced_count < MAX_ITEMS)
    {
        // Lock the mutex to access shared variables
        pthread_mutex_lock(&mutex);

        // Wait until there is space in the buffer
        while (counter == BUFFER_SIZE)
        {
            pthread_cond_wait(&empty, &mutex);
        }

        // Produce an item and add it to the buffer
        buffer[in] = item;
        printf("Produced: %d\n", item); // Print the produced item
        item++;                         // Increment the item number
        in = (in + 1) % BUFFER_SIZE;    // Update the index to the next position
        counter++;
        produced_count++; // Increment the count of produced items
        sleep(1);         // Sleep for 1 second to simulate work

        // Signal the consumer that there is an item in the buffer
        pthread_cond_signal(&full);
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL); // Exit the thread
}

// Consumer thread function
void *consumer(void *arg)
{
    while (consumed_count < MAX_ITEMS)
    {
        // Lock the mutex to access shared variables
        pthread_mutex_lock(&mutex);

        // Wait until there is an item in the buffer
        while (counter == 0)
        {
            pthread_cond_wait(&full, &mutex);
        }

        // Consume an item from the buffer
        int item = buffer[out];
        printf("Consumed: %d\n", item); // Print the consumed item
        out = (out + 1) % BUFFER_SIZE;  // Update the index to the next position
        counter--;
        consumed_count++; // Increment the count of consumed items
        sleep(1);         // Sleep for 1 second to simulate work

        // Signal the producer that there is space in the buffer
        pthread_cond_signal(&empty);
        // Unlock the mutex
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL); // Exit the thread
}

// Main function
int main()
{
    pthread_t producerThread, consumerThread; // Thread identifiers

    // Initialize mutex and condition variables
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&full, NULL);
    pthread_cond_init(&empty, NULL);

    // Create producer and consumer threads
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Wait for both threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0; // Return success
}
