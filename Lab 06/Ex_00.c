#include <stdio.h> // Include the standard input/output library

int fun1(int x, int y); // function prototype
void references_and_pointers();
void test();

// The main function - entry point of the program
int main()
{
    //test();
    references_and_pointers();

    // Return 0 to indicate successful execution
    return 0;
}
void test()
{
    // Print a message to the console
    printf("Welcome to C!\n");
    int x = 7;
    int y = 5;
    printf("x + y = %d \n", fun1(x, y));

}

int fun1(int x, int y)
{
    return x + y;
}

void references_and_pointers() {
    int x = 10;       // Variable
    int *ptr = &x;    // Pointer to 'x'
    //int &ref = x;    // Reference to 'x' //In C, there is no direct concept of a "reference" as in C++

    printf("Value of x: %d\n", x);       // Output: Value of x: 10
    printf("Address of x: %p\n", &x);    // Output: Address of x: (memory address)
    printf("Value of ptr: %p\n", ptr);   // Output: Value of ptr: (same memory address as &x)
    printf("Value pointed by ptr: %d\n", *ptr);  // Output: Value pointed by ptr: 10

    //printf("Value of x: %d\n", ref);

}