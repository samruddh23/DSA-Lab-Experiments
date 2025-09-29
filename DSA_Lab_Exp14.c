Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 14
Aim: Implementation of Menu driven Merge Sort and Quick Sort

Code:
#include <stdio.h>
#include <stdlib.h>

// Global array and size
int arr[100];
int n;

// Function to input array elements
void inputArray() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to display the array
void displayArray() {
    if (n == 0) {
        printf("Array is empty. Please input array first.\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/////////////////////////
// Merge Sort Functions
/////////////////////////
void merge(int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temp arrays
    int L[n1], R[n2];

    // Copy data
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge temp arrays
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy remaining elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

/////////////////////////
// Quick Sort Functions
/////////////////////////
int partition(int low, int high) {
    int pivot = arr[high];
    int i = (low - 1), temp;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap arr[i+1] and pivot
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

void quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);

        // Recursively sort elements before and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

////////////////////
// Main Program
////////////////////
int main() {
    int choice;

    while (1) {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Input Array\n");
        printf("2. Merge Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Display Array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            inputArray();
            break;
        case 2:
            if (n == 0) {
                printf("Array is empty. Please input array first.\n");
            } else {
                mergeSort(0, n - 1);
                printf("Array sorted using Merge Sort.\n");
            }
            break;
        case 3:
            if (n == 0) {
                printf("Array is empty. Please input array first.\n");
            } else {
                quickSort(0, n - 1);
                printf("Array sorted using Quick Sort.\n");
            }
            break;
        case 4:
            displayArray();
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

Output:

--- Sorting Menu ---
1. Input Array
2. Merge Sort
3. Quick Sort
4. Display Array
5. Exit
Enter your choice: 1
Enter number of elements: 5
Enter 5 elements:
27 33 6 42 49

--- Sorting Menu ---
1. Input Array
2. Merge Sort
3. Quick Sort
4. Display Array
5. Exit
Enter your choice: 4
Array elements: 27 33 6 42 49 

--- Sorting Menu ---
1. Input Array
2. Merge Sort
3. Quick Sort
4. Display Array
5. Exit
Enter your choice: 2
Array sorted using Merge Sort.

--- Sorting Menu ---
1. Input Array
2. Merge Sort
3. Quick Sort
4. Display Array
5. Exit
Enter your choice: 4
Array elements: 6 27 33 42 49 

--- Sorting Menu ---
1. Input Array
2. Merge Sort
3. Quick Sort
4. Display Array
5. Exit
Enter your choice: 1
Enter number of elements: 5
Enter 5 elements:
62 57 48 73 81

--- Sorting Menu ---
1. Input Array
2. Merge Sort
3. Quick Sort
4. Display Array
5. Exit
Enter your choice: 3
Array sorted using Quick Sort.

--- Sorting Menu ---
1. Input Array
2. Merge Sort
3. Quick Sort
4. Display Array
5. Exit
Enter your choice: 4
Array elements: 48 57 62 73 81 

--- Sorting Menu ---
1. Input Array
2. Merge Sort
3. Quick Sort
4. Display Array
5. Exit
Enter your choice: 5
Exiting...
