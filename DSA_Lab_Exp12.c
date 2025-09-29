Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 12 
Aim: Implementation of Binary Search in real life application

Scenario: Product Price Finder in an E-commerce Store
Suppose an e-commerce store maintains a sorted list of product prices. A customer wants to check whether a product priced at, say, ₹2999 exists. Instead of searching through every price, we use Binary Search to find it efficiently.
Code:
#include <stdio.h>

// Binary Search Function
int binarySearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;  // Not found
}

// Display array
void displayArray(int arr[], int size) {
    printf("Sorted Product Prices: ");
    for (int i = 0; i < size; i++)
        printf("₹%d ", arr[i]);
    printf("\n");
}

// Main function (menu-driven)
int main() {
    // Sorted product prices (could come from database or API)
    int prices[] = {499, 999, 1299, 1999, 2499, 2999, 3499, 3999, 4499, 4999};
    int size = sizeof(prices) / sizeof(prices[0]);

    int choice, key, result;

    while (1) {
        printf("\n--- Product Price Search ---\n");
        printf("1. Display Available Prices\n");
        printf("2. Search for a Price\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(prices, size);
                break;

            case 2:
                printf("Enter price to search (e.g., 2999): ₹");
                scanf("%d", &key);
                result = binarySearch(prices, size, key);
                if (result != -1)
                    printf("✅ Product found at index %d (₹%d).\n", result, prices[result]);
                else
                    printf("❌ Product priced at ₹%d not found.\n", key);
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

Output:
--- Product Price Search ---
1. Display Available Prices
2. Search for a Price
3. Exit
Enter your choice: 1
Sorted Product Prices: ₹499 ₹999 ₹1299 ₹1999 ₹2499 ₹2999 ₹3499 ₹3999 ₹4499 ₹4999

--- Product Price Search ---
Enter your choice: 2
Enter price to search (e.g., 2999): ₹2999
Product found at index 5 (₹2999).

--- Product Price Search ---
Enter your choice: 2
Enter price to search (e.g., 2999): ₹1500
Product priced at ₹1500 not found.

--- Product Price Search ---
Enter your choice: 3
Exiting program.
