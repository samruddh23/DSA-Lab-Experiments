Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 8
Aim: Implementation of Circular Doubly Linked List.

Code:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Insert at the end
void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }

    struct Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
}

// Delete by value
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* curr = head;
    struct Node* temp;

    // Traverse the list
    do {
        if (curr->data == key) {
            if (curr->next == curr) { // Only one node
                free(curr);
                head = NULL;
                return;
            }

            if (curr == head)
                head = head->next;

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
            return;
        }
        curr = curr->next;
    } while (curr != head);

    printf("Element %d not found.\n", key);
}

// Display forward
void displayForward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("List (Forward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Display backward
void displayBackward() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* tail = head->prev;
    struct Node* temp = tail;
    printf("List (Backward): ");
    do {
        printf("%d ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("\n");
}

// Main menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Doubly Linked List ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete Node by Value\n");
        printf("3. Display Forward\n");
        printf("4. Display Backward\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertEnd(value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;

        case 3:
            displayForward();
            break;

        case 4:
            displayBackward();
            break;

        case 5:
            printf("Exiting program.\n");
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

Output:

--- Circular Doubly Linked List ---
1. Insert at End
2. Delete Node by Value
3. Display Forward
4. Display Backward
5. Exit
Enter your choice: 1
Enter value to insert: 15

--- Circular Doubly Linked List ---
1. Insert at End
2. Delete Node by Value
3. Display Forward
4. Display Backward
5. Exit
Enter your choice: 1
Enter value to insert: 37

--- Circular Doubly Linked List ---
1. Insert at End
2. Delete Node by Value
3. Display Forward
4. Display Backward
5. Exit
Enter your choice: 1
Enter value to insert: 19

--- Circular Doubly Linked List ---
1. Insert at End
2. Delete Node by Value
3. Display Forward
4. Display Backward
5. Exit
Enter your choice: 3
List (Forward): 15 37 19 

--- Circular Doubly Linked List ---
1. Insert at End
2. Delete Node by Value
3. Display Forward
4. Display Backward
5. Exit
Enter your choice: 4
List (Backward): 19 37 15 

--- Circular Doubly Linked List ---
1. Insert at End
2. Delete Node by Value
3. Display Forward
4. Display Backward
5. Exit
Enter your choice: 2
Enter value to delete: 37

--- Circular Doubly Linked List ---
1. Insert at End
2. Delete Node by Value
3. Display Forward
4. Display Backward
5. Exit
Enter your choice: 3
List (Forward): 15 19 

--- Circular Doubly Linked List ---
1. Insert at End
2. Delete Node by Value
3. Display Forward
4. Display Backward
5. Exit
Enter your choice: 5
Exiting program.
