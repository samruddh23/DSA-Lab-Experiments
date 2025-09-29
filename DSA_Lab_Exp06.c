Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 6
Aim: Linked List implementation of Stack/queue in real life application.

PART 1: Stack using Linked List (Real-Life: Web Browser's Back Function)
Real-Life Scenario: A web browser uses a stack to manage the history of visited pages. When you click "Back", it pops the last visited page.

Code:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node for a browser history stack
struct Node {
    char url[100];
    struct Node* next;
};

struct Node* top = NULL;

// Push a URL onto the stack
void visitPage(char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->next = top;
    top = newNode;
    printf("Visited: %s\n", url);
}

// Pop a URL from the stack
void back() {
    if (top == NULL) {
        printf("No pages to go back to!\n");
        return;
    }

    printf("Going back from: %s\n", top->url);
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

// Display stack (history)
void showHistory() {
    if (top == NULL) {
        printf("No browsing history.\n");
        return;
    }

    struct Node* temp = top;
    printf("Browsing History (top to bottom):\n");
    while (temp != NULL) {
        printf("%s\n", temp->url);
        temp = temp->next;
    }
}

// Menu for Stack
void stackMenu() {
    int choice;
    char url[100];

    while (1) {
        printf("\n--- Browser Stack Menu ---\n");
        printf("1. Visit Page\n");
        printf("2. Back\n");
        printf("3. Show History\n");
        printf("4. Exit Stack Demo\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter URL: ");
                fgets(url, sizeof(url), stdin);
                url[strcspn(url, "\n")] = 0; // Remove newline
                visitPage(url);
                break;
            case 2:
                back();
                break;
            case 3:
                showHistory();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

PART 2: Queue using Linked List (Real-Life: Customer Service Call Center)
Real-Life Scenario: A call center system serves callers in the order they call — First Come First Served — perfect use case for a queue.
Code:
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct QNode {
    char name[100];
    struct QNode* next;
};

struct QNode *front = NULL, *rear = NULL;

// Enqueue a customer
void addCustomer(char* name) {
    struct QNode* newNode = (struct QNode*)malloc(sizeof(struct QNode));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("Customer added: %s\n", name);
}

// Dequeue a customer
void serveCustomer() {
    if (front == NULL) {
        printf("No customers in queue.\n");
        return;
    }

    printf("Serving customer: %s\n", front->name);
    struct QNode* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Display queue
void showQueue() {
    if (front == NULL) {
        printf("No customers in queue.\n");
        return;
    }

    printf("Customers in queue:\n");
    struct QNode* temp = front;
    while (temp != NULL) {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

// Menu for Queue
void queueMenu() {
    int choice;
    char name[100];

    while (1) {
        printf("\n--- Call Center Queue Menu ---\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Show Queue\n");
        printf("4. Exit Queue Demo\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                printf("Enter customer name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                addCustomer(name);
                break;
            case 2:
                serveCustomer();
                break;
            case 3:
                showQueue();
                break;
            case 4:
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

Main Function: Combined Menu
Code:
int main() {
    int mainChoice;

    while (1) {
        printf("\n=== Main Menu ===\n");
        printf("1. Stack (Browser History)\n");
        printf("2. Queue (Call Center)\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        switch (mainChoice) {
            case 1:
                stackMenu();
                break;
            case 2:
                queueMenu();
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}

Output:
=== Main Menu ===
1. Stack (Browser History)
2. Queue (Call Center)
3. Exit
Enter your choice: 1

--- Browser Stack Menu ---
1. Visit Page
2. Back
3. Show History
4. Exit Stack Demo
Enter your choice: 1
Enter URL: google.com
Visited: google.com

--- Browser Stack Menu ---
1. Visit Page
Enter your choice: 1
Enter URL: openai.com
Visited: openai.com

--- Browser Stack Menu ---
3
Browsing History (top to bottom):
openai.com
google.com

--- Browser Stack Menu ---
2
Going back from: openai.com

