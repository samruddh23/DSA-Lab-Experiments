Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 1
Aim: Implementation of Stack Data Structure using array

Code:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Check if stack is full
int isFull(struct Stack *stack) {
    return stack->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Push operation
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Pop operation
void pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    int popped = stack->arr[stack->top--];
    printf("Popped element: %d\n", popped);
}

// Peek operation
void peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element is: %d\n", stack->arr[stack->top]);
}

// Display operation
void display(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements (top to bottom):\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d\n", stack->arr[i]);
    }
}

int main() {
    struct Stack myStack;
    initialize(&myStack);

    int choice, value;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&myStack, value);
                break;
            case 2:
                pop(&myStack);
                break;
            case 3:
                peek(&myStack);
                break;
            case 4:
                display(&myStack);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter 1-5.\n");
        }
    }

    return 0;

  Output:
  --- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 1
Enter value to push: 20
Pushed 20 onto the stack.

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 1
Enter value to push: 23
Pushed 23 onto the stack.

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 4
Stack elements (top to bottom):
23
20

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 2
Popped element: 23

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 3
Top element is: 20

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display
5. Exit
Enter your choice (1-5): 5
Exiting program.
}
