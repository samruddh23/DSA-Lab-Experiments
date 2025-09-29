Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 7
Aim: Implementation of Circular Singly Linked List.

Code:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert at end
void insertEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Function to delete a node by value
void deleteNode(int key) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *curr = head, *prev = NULL;

    // If head is to be deleted
    if (head->data == key) {
        // If only one node
        if (head->next == head) {
            free(head);
            head = NULL;
            return;
        }

        // Find last node
        struct Node* last = head;
        while (last->next != head)
            last = last->next;

        last->next = head->next;
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // Deleting other than head
    do {
        prev = curr;
        curr = curr->next;
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr != head);

    printf("Element %d not found.\n", key);
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Menu-driven main
int main() {
    int choice, val;

    while (1) {
        printf("\n--- Circular Singly Linked List ---\n");
        printf("1. Insert at End\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insertEnd(val);
            break;
        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &val);
            deleteNode(val);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

Output:

--- Circular Singly Linked List ---
1. Insert at End
2. Delete Node
3. Display List
4. Exit
Enter your choice: 1
Enter value to insert: 93

--- Circular Singly Linked List ---
1. Insert at End
2. Delete Node
3. Display List
4. Exit
Enter your choice: 1
Enter value to insert: 87

--- Circular Singly Linked List ---
1. Insert at End
2. Delete Node
3. Display List
4. Exit
Enter your choice: 1
Enter value to insert: 55

--- Circular Singly Linked List ---
1. Insert at End
2. Delete Node
3. Display List
4. Exit
Enter your choice: 3
Circular Linked List: 93 87 55 

--- Circular Singly Linked List ---
1. Insert at End
2. Delete Node
3. Display List
4. Exit
Enter your choice: 2
Enter value to delete: 87

--- Circular Singly Linked List ---
1. Insert at End
2. Delete Node
3. Display List
4. Exit
Enter your choice: 3
Circular Linked List: 93 55 

--- Circular Singly Linked List ---
1. Insert at End
2. Delete Node
3. Display List
4. Exit
Enter your choice: 4
Exiting program.
