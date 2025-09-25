Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 9
Aim: Implementation of Binary Search Tree .

Code:
#include <stdio.h>
#include <stdlib.h>

// Node structure for BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Search a node in BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node* root = NULL;
    int choice, value, key;
    struct Node* result;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                result = search(root, key);
                if (result != NULL)
                    printf("%d found in the tree.\n", key);
                else
                    printf("%d not found in the tree.\n", key);
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter 1-6.\n");
        }
    }

    return 0;
}

Ouput:
--- Binary Search Tree Menu ---
1. Insert
2. Search
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter your choice (1-6): 1
Enter value to insert: 20

--- Binary Search Tree Menu ---
1. Insert
2. Search
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter your choice (1-6): 1
Enter value to insert: 60

--- Binary Search Tree Menu ---
1. Insert
2. Search
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter your choice (1-6): 1
Enter value to insert: 35

--- Binary Search Tree Menu ---
1. Insert
2. Search
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter your choice (1-6): 1
Enter value to insert: 
2


--- Binary Search Tree Menu ---
1. Insert
2. Search
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter your choice (1-6): 3
Inorder traversal: 2 20 35 60 

--- Binary Search Tree Menu ---
1. Insert
2. Search
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter your choice (1-6): 4
Preorder traversal: 20 2 60 35 

--- Binary Search Tree Menu ---
1. Insert
2. Search
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter your choice (1-6): 5
Postorder traversal: 2 35 60 20 

--- Binary Search Tree Menu ---
1. Insert
2. Search
3. Inorder
4. Preorder
5. Postorder
6. Exit
Enter your choice (1-6): 6
Exiting program.
