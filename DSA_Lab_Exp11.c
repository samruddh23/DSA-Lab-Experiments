Name: Samruddh Jadhav
Roll No.20 
Division: D10C
Lab Experiment 11
Aim: Implementation of BFS and DFS on a directed graph using an adjacency matrix.

Code:
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Visited array
int queue[MAX];     // Queue for BFS
int n;              // Number of vertices

// Function to create the graph
void createGraph() {
    int edges, origin, destination;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (origin destination) [0-based indexing]:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &origin, &destination);
        if (origin >= 0 && origin < n && destination >= 0 && destination < n) {
            adj[origin][destination] = 1;
        } else {
            printf("Invalid edge!\n");
            i--; // Retry this edge
        }
    }
}

// DFS (recursive)
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// BFS (queue-based)
void BFS(int start) {
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Enqueue start vertex
    queue[++rear] = start;
    visited[start] = 1;

    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

// Display adjacency matrix
void displayAdjMatrix() {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

// Main menu
int main() {
    int choice, start;

    while (1) {
        printf("\n--- Graph Traversal Menu ---\n");
        printf("1. Create Graph\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. DFS Traversal\n");
        printf("4. BFS Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createGraph();
            break;
        case 2:
            displayAdjMatrix();
            break;
        case 3:
            if (n == 0) {
                printf("Graph not created yet!\n");
                break;
            }
            printf("Enter starting vertex (0 to %d): ", n - 1);
            scanf("%d", &start);
            if (start < 0 || start >= n) {
                printf("Invalid starting vertex!\n");
                break;
            }
            for (int i = 0; i < n; i++)
                visited[i] = 0;
            printf("DFS Traversal starting from vertex %d: ", start);
            DFS(start);
            printf("\n");
            break;
        case 4:
            if (n == 0) {
                printf("Graph not created yet!\n");
                break;
            }
            printf("Enter starting vertex (0 to %d): ", n - 1);
            scanf("%d", &start);
            if (start < 0 || start >= n) {
                printf("Invalid starting vertex!\n");
                break;
            }
            printf("BFS Traversal starting from vertex %d: ", start);
            BFS(start);
            printf("\n");
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
--- Graph Traversal Menu ---
1. Create Graph
2. Display Adjacency Matrix
3. DFS Traversal
4. BFS Traversal
5. Exit
Enter your choice: 1
Enter number of vertices: 4
Enter number of edges: 5
Enter edges (origin destination) [0-based indexing]:
0 1
0 2
1 2
2 0
2 3

--- Graph Traversal Menu ---
2
Adjacency Matrix:
0 1 1 0 
0 0 1 0 
1 0 0 1 
0 0 0 0 

--- Graph Traversal Menu ---
3
Enter starting vertex (0 to 3): 2
DFS Traversal starting from vertex 2: 2 0 1 3 

--- Graph Traversal Menu ---
4
Enter starting vertex (0 to 3): 2
BFS Traversal starting from vertex 2: 2 0 3 1 

--- Graph Traversal Menu ---
5
Exiting...
