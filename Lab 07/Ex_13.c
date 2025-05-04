// Thread-Safe Stack (Intermediate)
// Problem: Implement a shared stack with push/pop operations.

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define STACK_SIZE 10
int stack[STACK_SIZE];
int top = -1;
pthread_mutex_t stack_mutex = PTHREAD_MUTEX_INITIALIZER;

void push(int val)
{
    pthread_mutex_lock(&stack_mutex);
    if (top < STACK_SIZE - 1)
    {
        stack[++top] = val;
        printf("Pushed %d\n", val);
    }
    else
    {
        printf("Stack overflow!\n");
    }
    pthread_mutex_unlock(&stack_mutex);
}

int pop()
{
    pthread_mutex_lock(&stack_mutex);
    int val = -1;
    if (top >= 0)
    {
        val = stack[top--];
        printf("Popped %d\n", val);
    }
    else
    {
        printf("Stack underflow!\n");
    }
    pthread_mutex_unlock(&stack_mutex);
    return val;
}

void *stack_worker(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        push(i); // Thread-safe push
        pop();   // Thread-safe pop
    }
    return NULL;
}

int main()
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, stack_worker, NULL);
    pthread_create(&t2, NULL, stack_worker, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&stack_mutex);
    return 0;
}