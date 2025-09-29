Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 13
Aim: Implementation of Menu driven Selection sort, Bubble sort, Insertion sort

Code:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int arr[MAX];
int n = 0;

// Function to input array
void inputArray() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        n = 0;
        return;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display array
void displayArray() {
    if (n == 0) {
        printf("Array is empty. Please input the array first.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Selection Sort
void selectionSort() {
    if (n == 0) {
        printf("Array is empty. Please input the array first.\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        // Swap arr[i] and arr[min_idx]
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
    printf("Array sorted using Selection Sort.\n");
}

// Bubble Sort
void bubbleSort() {
    if (n == 0) {
        printf("Array is empty. Please input the array first.\n");
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; // Optimized for already sorted array
    }
    printf("Array sorted using Bubble Sort.\n");
}

// Insertion Sort
void insertionSort() {
    if (n == 0) {
        printf("Array is empty. Please input the array first.\n");
        return;
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
    printf("Array sorted using Insertion Sort.\n");
}

// Main function
int main() {
    int choice;

    while (1) {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Input Array\n");
        printf("2. Selection Sort\n");
        printf("3. Bubble Sort\n");
        printf("4. Insertion Sort\n");
        printf("5. Display Array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            inputArray();
            break;
        case 2:
            selectionSort();
            break;
        case 3:
            bubbleSort();
            break;
        case 4:
            insertionSort();
            break;
        case 5:
            displayArray();
            break;
        case 6:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

Output:
--- Sorting Menu ---
1. Input Array
2. Selection Sort
3. Bubble Sort
4. Insertion Sort
5. Display Array
6. Exit
Enter your choice: 1
Enter number of elements: 6
Enter 6 elements:
33 67 56 89 23 17

--- Sorting Menu ---
1. Input Array
2. Selection Sort
3. Bubble Sort
4. Insertion Sort
5. Display Array
6. Exit
Enter your choice: 5
Array elements: 33 67 56 89 23 17 

--- Sorting Menu ---
1. Input Array
2. Selection Sort
3. Bubble Sort
4. Insertion Sort
5. Display Array
6. Exit
Enter your choice: 2
Array sorted using Selection Sort.

--- Sorting Menu ---
1. Input Array
2. Selection Sort
3. Bubble Sort
4. Insertion Sort
5. Display Array
6. Exit
Enter your choice: 5
Array elements: 17 23 33 56 67 89 

--- Sorting Menu ---
1. Input Array
2. Selection Sort
3. Bubble Sort
4. Insertion Sort
5. Display Array
6. Exit
Enter your choice: 4
Array sorted using Insertion Sort.

--- Sorting Menu ---
1. Input Array
2. Selection Sort
3. Bubble Sort
4. Insertion Sort
5. Display Array
6. Exit
Enter your choice: 5
Array elements: 17 23 33 56 67 89 

--- Sorting Menu ---
1. Input Array
2. Selection Sort
3. Bubble Sort
4. Insertion Sort
5. Display Array
6. Exit
Enter your choice: 6
Exiting...
