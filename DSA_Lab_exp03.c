Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 3
Aim: Implementation of Linear Queue Data Structure using array

Code:
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Enqueue operation
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = value;
    printf("%d enqueued successfully.\n", value);
}

// Dequeue operation
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot dequeue.\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front++]);
}

// Peek operation
void peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element: %d\n", queue[front]);
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Linear Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

Output:
--- Linear Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 1
Enter value to enqueue: 36
36 enqueued successfully.

--- Linear Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 1
Enter value to enqueue: 43
43 enqueued successfully.

--- Linear Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 3
Front element: 36

--- Linear Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 4
Queue elements: 36 43 

--- Linear Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 2
Dequeued element: 36

--- Linear Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 5

