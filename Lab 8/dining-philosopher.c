// https://www.geeksforgeeks.org/dining-philosopher-problem-using-semaphores/
#include <pthread.h>   // Library for handling threads in C
#include <semaphore.h> // Library for handling semaphores in C
#include <stdio.h>     // Standard I/O library in C
#include <unistd.h>    // Library for sleep function

// Defining constants
#define N 6        // Number of philosophers and forks
#define THINKING 2 // Constant representing the "thinking" state
#define HUNGRY 1   // Constant representing the "hungry" state
#define EATING 0   // Constant representing the "eating" state

// Macros to determine the philosopher to the left and right
#define LEFT (phnum + (N - 1)) % N // Philosopher to the left
#define RIGHT (phnum + 1) % N      // Philosopher to the right

// Array to hold the state of each philosopher (THINKING, HUNGRY, or EATING)
int state[N];

// Array to hold the philosopher numbers (0 to N-1)
int phil[N];

// Declaration of semaphores
sem_t mutex; // Semaphore for mutual exclusion when accessing shared resources
sem_t S[N];  // Semaphores for each philosopher, used to control their eating

int numEater = 0;// Count of active eaters

// Function to check if the philosopher can start eating
void test(int phnum)
{
    // If the current philosopher is hungry and both neighbors are not eating
    if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        // Change state to eating
        state[phnum] = EATING;
        numEater++;
        // Simulate eating process (sleep for 2 seconds)
        sleep(2);

        // Print which forks the philosopher is taking and that they are eating
        printf("Philosopher %d takes fork %d and %d\n",
               phnum + 1, LEFT + 1, phnum + 1);
        printf("Philosopher %d is Eating\n", phnum + 1);

        // printf("no current Eating Philosophers = %d\n", nocurrentEating);

        // Signal the philosopher's semaphore to allow them to proceed
        sem_post(&S[phnum]);
        // sem_post(&S[phnum]) has no effect during takefork
        // used to wake up hungry philosophers during putfork
    }
}

// Function to simulate a philosopher taking forks
void take_fork(int phnum)
{
    // Lock the critical section using mutex to ensure mutual exclusion
    sem_wait(&mutex);

    // Set the state to hungry
    state[phnum] = HUNGRY;
    printf("Philosopher %d is Hungry\n", phnum + 1);

    // Check if the philosopher can eat
    test(phnum);

    // Unlock the critical section
    sem_post(&mutex);

    // If unable to eat, the philosopher waits for a signal
    sem_wait(&S[phnum]);

    // Simulate the time taken to pick up forks (sleep for 1 second)
    sleep(1);
}

// Function to simulate a philosopher putting down forks
void put_fork(int phnum)
{
    // Lock the critical section using mutex to ensure mutual exclusion
    sem_wait(&mutex);

    // Set the state to thinking
    state[phnum] = THINKING;
    numEater--;
    // Print that the philosopher is putting down forks and is thinking
    printf("Philosopher %d putting fork %d and %d down\n",
           phnum + 1, LEFT + 1, phnum + 1);
    printf("Philosopher %d is thinking\n", phnum + 1);

    // Test if the left and right philosophers can now eat
    test(LEFT);
    test(RIGHT);

    // Unlock the critical section
    sem_post(&mutex);
}

// Function representing the actions of a philosopher
void *philosopher(void *num)
{
    int f = 1;
    // Run indefinitely (simulate a philosopher's life cycle)
    while (1)
    {
        int *i = num; // Cast the argument to an integer pointer

        // Simulate thinking process (sleep for 1 second)
        sleep(1);

        // Try to take forks and eat
        take_fork(*i);

        // Simulate eating time
        sleep(0);

        // Put down forks after eating
        put_fork(*i);

        printf("number current Eating Philosophers = %d\n", numEater);
        f = 0;
    }
}

// Main function
int main()
{
    int i;                  // Loop variable
    pthread_t thread_id[N]; // Array to hold thread IDs for philosophers

    // Initialize the mutex semaphore with a value of 1 (binary semaphore)
    sem_init(&mutex, 0, 1);

    // Initialize the philosopher semaphores with a value of 0 (blocked initially)
    for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);

    // Initialize Array to hold the philosopher numbers (0 to N-1)
    for (i = 0; i < N; i++)
        phil[i] = i;

    // Create philosopher threads
    for (i = 0; i < N; i++)
    {
        // Create a thread for each philosopher, passing the philosopher number as an argument
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);

        // Print that the philosopher is thinking
        printf("Philosopher %d is thinking\n", i + 1);
    }

    // Join the philosopher threads (wait for them to finish, though they never do)
    for (i = 0; i < N; i++)
        pthread_join(thread_id[i], NULL);
}
