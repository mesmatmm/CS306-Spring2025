#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

/*
This program provides a possible solution for the first readers-writers problem using
a mutex and a semaphore. The program uses 10 readers and 5 writers to demonstrate the
 solution. You can adjust these values as needed.
*/

// Semaphore to control access to the shared resource
sem_t wrt;
// Mutex to protect the numreader variable
pthread_mutex_t mutex;
// Shared resource
int cnt = 1;
// Count of active readers
int numreader = 0;

// Writer function
void *writer(void *wno)
{
    // Wait for the semaphore, blocking access for readers
    sem_wait(&wrt);
    // Modify the shared resource
    cnt = cnt * 2;
    printf("Writer %d modified cnt to %d\n", (*((int *)wno)), cnt);
    // Signal the semaphore, allowing readers to access the resource
    sem_post(&wrt);
}

// Reader function
void *reader(void *rno)
{
    // Reader acquires the mutex lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader++;
    if (numreader == 1)
    {
        // If this is the first reader, block the writer
        sem_wait(&wrt);
    }
    pthread_mutex_unlock(&mutex);

    // Reading Section
    printf("Reader %d: read cnt as %d\n", *((int *)rno), cnt);

    // After Reading is Done: Now a reader wants to leave
    // Reader acquires the mutex lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader--;
    if (numreader == 0)
    {
        // If this is the last reader, wake up the writer
        sem_post(&wrt);
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{
    // Arrays to hold reader and writer thread identifiers
    pthread_t read[10], write[5];

    // Initialize the mutex and semaphore
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);

    // Array used for numbering the readers and writers
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Create reader threads
    for (int i = 0; i < 10; i++)
    {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    // Create writer threads
    for (int i = 0; i < 5; i++)
    {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    // Wait for all reader threads to finish
    for (int i = 0; i < 10; i++)
    {
        pthread_join(read[i], NULL);
    }
    // Wait for all writer threads to finish
    for (int i = 0; i < 5; i++)
    {
        pthread_join(write[i], NULL);
    }

    // Destroy the mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
