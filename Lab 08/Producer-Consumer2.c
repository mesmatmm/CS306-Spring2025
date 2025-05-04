#include <stdio.h>     // Standard input and output library
#include <stdlib.h>    // Standard library for memory allocation, process control, etc.
#include <pthread.h>   // POSIX thread library for creating and managing threads
#include <semaphore.h> // Semaphore library for synchronization

#define BUFFER_SIZE 5 // Define the size of the buffer
#define MAX_ITEMS 20  // Define the maximum number of items to be produced and consumed

int buffer[BUFFER_SIZE]; // Shared buffer array
int in = 0;              // Index for the next item to be inserted by the producer
int out = 0;             // Index for the next item to be removed by the consumer
int produced_count = 0;  // Counter to track the number of items produced
int consumed_count = 0;  // Counter to track the number of items consumed

sem_t mutex; // Semaphore for mutual exclusion (protecting critical sections)
sem_t full;  // Semaphore to track the number of full slots in the buffer
sem_t empty; // Semaphore to track the number of empty slots in the buffer

// Producer thread function
void *producer(void *arg)
{
    int item = 1; // Start producing items with the value 1

    // Continue producing items until the maximum count is reached
    while (produced_count < MAX_ITEMS)
    {
        sem_wait(&empty); // Wait if there are no empty slots
        sem_wait(&mutex); // Lock the critical section

        // Insert the item into the buffer
        buffer[in] = item;
        printf("Produced: %d\n", item); // Print the produced item
        item++;                         // Increment the item value for the next production
        in = (in + 1) % BUFFER_SIZE;    // Update the index circularly

        produced_count++; // Increment the produced count

        sem_post(&mutex); // Unlock the critical section
        sem_post(&full);  // Signal that a new item is produced (full slot available)
    }

    pthread_exit(NULL); // Exit the thread
}

// Consumer thread function
void *consumer(void *arg)
{
    // Continue consuming items until the maximum count is reached
    while (consumed_count < MAX_ITEMS)
    {
        sem_wait(&full);  // Wait if there are no full slots
        sem_wait(&mutex); // Lock the critical section

        // Remove the item from the buffer
        int item = buffer[out];
        printf("Consumed: %d\n", item); // Print the consumed item
        out = (out + 1) % BUFFER_SIZE;  // Update the index circularly

        consumed_count++; // Increment the consumed count

        sem_post(&mutex); // Unlock the critical section
        sem_post(&empty); // Signal that an item has been consumed (empty slot available)
    }

    pthread_exit(NULL); // Exit the thread
}

int main()
{
    pthread_t producerThread, consumerThread; // Declare thread variables

    // Initialize semaphores
    sem_init(&mutex, 0, 1);           // Initialize mutex to 1 (binary semaphore)
    sem_init(&full, 0, 0);            // Initialize full to 0 (no items produced initially)
    sem_init(&empty, 0, BUFFER_SIZE); // Initialize empty to BUFFER_SIZE

    // Create producer and consumer threads
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Wait for the threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy semaphores
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0; // Exit the program
}
