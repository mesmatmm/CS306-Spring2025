#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Define a struct with different variable types
typedef struct
{
    int id;
    char name[50];
    float price;
    double weight;
    bool in_stock;
    char category;
} Product;

// Function prototypes (methods for the struct)
void print_product(Product p);
void increase_price(Product *p, float amount);
void toggle_stock_status(Product *p);
Product create_default_product();
Product create_custom_product(int id, const char *name, float price, double weight, bool stock, char cat);

int main()
{
    printf("=== Struct Example in C ===\n\n");

    // Method 1: Initialize struct members one by one
    Product p1;
    p1.id = 101;
    strcpy(p1.name, "Laptop");
    p1.price = 999.99f;
    p1.weight = 2.5;
    p1.in_stock = true;
    p1.category = 'E';

    printf("Product 1 (initialized individually):\n");
    print_product(p1);

    // Method 2: Initialize at declaration using designated initializers
    Product p2 = {
        .id = 102,
        .name = "Smartphone",
        .price = 699.99f,
        .weight = 0.3,
        .in_stock = false,
        .category = 'E'};

    printf("\nProduct 2 (designated initializers):\n");
    print_product(p2);

    // Method 3: Initialize in declaration order
    Product p3 = {103, "Desk Chair", 149.99f, 8.75, true, 'F'};

    printf("\nProduct 3 (ordered initializers):\n");
    print_product(p3);

    // Method 4: Using a constructor-like function
    Product p4 = create_default_product();

    printf("\nProduct 4 (default constructor):\n");
    print_product(p4);

    // Method 5: Using a custom constructor function
    Product p5 = create_custom_product(105, "Coffee Mug", 12.49f, 0.4, true, 'H');

    printf("\nProduct 5 (custom constructor):\n");
    print_product(p5);

    // Demonstrate struct modification functions
    printf("\nIncreasing price of Product 1 by $50.00...\n");
    increase_price(&p1, 50.0f);
    print_product(p1);

    printf("\nToggling stock status of Product 2...\n");
    toggle_stock_status(&p2);
    print_product(p2);

    return 0;
}

// Function to print product details
void print_product(Product p)
{
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Price: $%.2f\n", p.price);
    printf("Weight: %.2f kg\n", p.weight);
    printf("In Stock: %s\n", p.in_stock ? "Yes" : "No");
    printf("Category: %c\n", p.category);
    printf("----------------------------\n");
}

// Function to increase product price
void increase_price(Product *p, float amount)
{
    p->price += amount;
    printf("Price increased by $%.2f\n", amount);
}

// Function to toggle stock status
void toggle_stock_status(Product *p)
{
    p->in_stock = !p->in_stock;
    printf("Stock status toggled\n");
}

// Constructor-like function for default product
Product create_default_product()
{
    Product p = {
        .id = 0,
        .name = "Unknown",
        .price = 0.0f,
        .weight = 0.0,
        .in_stock = false,
        .category = 'U'};
    return p;
}

// Constructor-like function for custom product
Product create_custom_product(int id, const char *name, float price, double weight, bool stock, char cat)
{
    Product p;
    p.id = id;
    strncpy(p.name, name, sizeof(p.name) - 1);
    p.name[sizeof(p.name) - 1] = '\0'; // Ensure null-termination
    p.price = price;
    p.weight = weight;
    p.in_stock = stock;
    p.category = cat;
    return p;
}