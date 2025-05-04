//  Bank Account Simulation (Intermediate)
// Problem: Safely manage concurrent deposits/withdrawals from a shared bank account.
// mutex lock with each account

#include <stdio.h>
#include <pthread.h>

typedef struct
{
    double balance;
    pthread_mutex_t lock;
} BankAccount;

void deposit(BankAccount *acc, double amount)
{
    pthread_mutex_lock(&acc->lock);
    acc->balance += amount;
    printf("Deposited $%.2f, new balance: $%.2f\n", amount, acc->balance);
    pthread_mutex_unlock(&acc->lock);
}

void withdraw(BankAccount *acc, double amount)
{
    pthread_mutex_lock(&acc->lock);
    if (acc->balance >= amount)
    {
        acc->balance -= amount;
        printf("Withdrew $%.2f, new balance: $%.2f\n", amount, acc->balance);
    }
    else
    {
        printf("Failed to withdraw $%.2f (insufficient funds)\n", amount);
    }
    pthread_mutex_unlock(&acc->lock);
}

void *account_activity(void *arg)
{
    BankAccount *acc = (BankAccount *)arg;
    for (int i = 0; i < 5; i++)
    {
        deposit(acc, 100.50);
        withdraw(acc, 75.25);
    }
    return NULL;
}

int main()
{
    BankAccount acc = {.balance = 500.00, .lock = PTHREAD_MUTEX_INITIALIZER};
    pthread_t t1, t2;

    pthread_create(&t1, NULL, account_activity, &acc);
    pthread_create(&t2, NULL, account_activity, &acc);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final balance: $%.2f\n", acc.balance);

    pthread_mutex_destroy(&acc.lock);

    return 0;
}