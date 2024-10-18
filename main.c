#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];

// A simple Queue structure for BFS
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Initialize the queue (start empty)
void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

// Check if the queue is empty
int isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

// Add a value to the queue
void enqueue(Queue* q, int value) {
    if (q->rear < MAX) {
        q->items[q->rear++] = value;  // Add the value at the rear
    }
}

// Remove a value from the queue and return it
int dequeue(Queue* q) {
    return q->items[q->front++];  // Return the front value
}

// Perform BFS starting from a given vertex
void performBFS(int startVertex, int vertexCount) {
    Queue queue;
    initQueue(&queue);  // Initialize the queue
    visited[startVertex] = 1;  // Mark the start vertex as visited
    enqueue(&queue, startVertex);  // Enqueue the start vertex

    printf("BFS Order: ");  // To show the order of visiting nodes

    // Continue until all reachable nodes are visited
    while (!isQueueEmpty(&queue)) {
        int currentVertex = dequeue(&queue);  // Dequeue a vertex
        printf("%d ", currentVertex);  // Print the current vertex

        // Check its neighbors (adjacent vertices)
        for (int i = 0; i < vertexCount; i++) {
            // If there's an edge and the neighbor isn't visited yet
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;  // Mark it as visited
                enqueue(&queue, i);  // Enqueue the neighbor
            }
        }
    }
    printf("\n");  // End of BFS order
}

// Set up the graph by asking the user for vertices and edges
void initializeGraph(int* vertexCount, int* edgeCount) {
    printf("Enter the number of vertices: ");
    scanf("%d", vertexCount);  // Get the number of vertices

    // Initialize the adjacency matrix to zero (no connections)
    for (int i = 0; i < *vertexCount; i++) {
        for (int j = 0; j < *vertexCount; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;  // Set all vertices as unvisited initially
    }

    printf("Enter the number of edges: ");
    scanf("%d", edgeCount);  // Get the number of edges

    // Get the edges from the user
    for (int i = 0; i < *edgeCount; i++) {
        int u, v;
        printf("Enter edge (u, v): ");
        scanf("%d %d", &u, &v);  // Get two vertices that form an edge

        if (u < *vertexCount && v < *vertexCount) {
            adjMatrix[u][v] = 1;  // Set the connection in the matrix
            adjMatrix[v][u] = 1;  // Since it's an undirected graph
        } else {
            printf("Invalid edge: (%d, %d)\n", u, v);
            i--;  // Retry if the edge is invalid
        }
    }
}

int main() {
    int vertexCount, edgeCount, startVertex;

    // Initialize the graph (take input for vertices and edges)
    initializeGraph(&vertexCount, &edgeCount);

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);  // Get the starting vertex for BFS

    // Check if the starting vertex is valid
    if (startVertex >= 0 && startVertex < vertexCount) {
        printf("Breadth-First Search starting from vertex %d:\n", startVertex);
        performBFS(startVertex, vertexCount);  // Perform BFS
    } else {
        printf("Invalid starting vertex.\n");
    }

    return 0;
}


