#include <stdio.h>
#define MAX 100

int adjMatrix[MAX][MAX];  // Adjacency matrix to represent the graph
int visited[MAX];         // Array to track visited vertices

// Depth First Search (DFS) function
void depthFirstSearch(int vertex, int vertexCount) {
    visited[vertex] = 1;  // Mark the current vertex as visited
    printf("%d ", vertex);  // Print the visited vertex

    // Recur for all adjacent vertices
    for (int i = 0; i < vertexCount; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            depthFirstSearch(i, vertexCount);  // Recursive DFS call
        }
    }
}

// Function to initialize the graph
void initializeGraph(int* vertexCount, int* edgeCount) {
    printf("Enter the number of vertices: ");
    scanf("%d", vertexCount);  // Input the number of vertices

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < *vertexCount; i++) {
        for (int j = 0; j < *vertexCount; j++) {
            adjMatrix[i][j] = 0;  // Set all edges to 0 (no edges initially)
        }
        visited[i] = 0;  // Set all vertices as unvisited
    }

    printf("Enter the number of edges: ");
    scanf("%d", edgeCount);  // Input the number of edges

    // Input edges between vertices
    for (int i = 0; i < *edgeCount; i++) {
        int u, v;
        printf("Enter edge (u, v): ");
        scanf("%d %d", &u, &v);  // Input vertices u and v to connect

        if (u < *vertexCount && v < *vertexCount) {
            adjMatrix[u][v] = 1;  // Mark the edge in adjacency matrix
            adjMatrix[v][u] = 1;  // For undirected graph, add both ways
        } else {
            printf("Invalid edge: (%d, %d)\n", u, v);  // Invalid edge case
            i--;  // Retry input for the same edge
        }
    }
}

int main() {
    int vertexCount, edgeCount, startVertex;

    // Initialize the graph with user input
    initializeGraph(&vertexCount, &edgeCount);

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);  // Input the starting vertex for DFS

    // Check if the starting vertex is valid
    if (startVertex >= 0 && startVertex < vertexCount) {
        printf("Depth-First Search starting from vertex %d:\n", startVertex);
        depthFirstSearch(startVertex, vertexCount);  // Perform DFS
    } else {
        printf("Invalid starting vertex.\n");
    }

    return 0;
}
