#include <stdio.h>
#include <stdlib.h>

// Define the adjacency matrix structure
typedef struct {
    int** matrix;  // 2D array to store the matrix
    int size;  // Size of the matrix
} AdjacencyMatrix;

// Create a matrix of size x size and initialize all elements to 0
AdjacencyMatrix* createMatrix(int size) {
    AdjacencyMatrix* adjMatrix = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
    adjMatrix->size = size;

    // Allocate memory for the 2D array to store the matrix
    adjMatrix->matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        adjMatrix->matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            adjMatrix->matrix[i][j] = 0;  // Initialize all elements to 0
        }
    }

    return adjMatrix;
}

// Add an edge between nodes 'from' and 'to'
void addEdge(AdjacencyMatrix* adjMatrix, int from, int to) {
    adjMatrix->matrix[from][to] = 1;
}

// Get the value stored at row 'row' and column 'col'
int getValue(AdjacencyMatrix* adjMatrix, int row, int col) {
    return adjMatrix->matrix[row][col];
}

// Destroy the adjacency matrix (free memory)
void destroyMatrix(AdjacencyMatrix* adjMatrix) {
    for (int i = 0; i < adjMatrix->size; i++) {
        free(adjMatrix->matrix[i]);
    }
    free(adjMatrix->matrix);
    free(adjMatrix);
}

// Display the adjacency matrix
void displayMatrix(AdjacencyMatrix* adjMatrix) {
    for (int i = 0; i < adjMatrix->size; i++) {
        for (int j = 0; j < adjMatrix->size; j++) {
            printf("%d ", adjMatrix->matrix[i][j]);
        }
        printf("\n");
    }
}

// Given a node N, return the set of all predecessor nodes (nodes that have an edge to N)
int* getPredecessors(AdjacencyMatrix* adjMatrix, int node) {
    int* predecessors = (int*)malloc(adjMatrix->size * sizeof(int));
    int count = 0;

    for (int i = 0; i < adjMatrix->size; i++) {
        if (adjMatrix->matrix[i][node] == 1) {
            predecessors[count++] = i;
        }
    }

    return predecessors;
}

// Given a node N, return the set of all successor nodes (nodes that N has an edge to)
int* getSuccessors(AdjacencyMatrix* adjMatrix, int node) {
    int* successors = (int*)malloc(adjMatrix->size * sizeof(int));
    int count = 0;

    for (int i = 0; i < adjMatrix->size; i++) {
        if (adjMatrix->matrix[node][i] == 1) {
            successors[count++] = i;
        }
    }

    successors[count] = 0;  // Add 0 as the end marker in the array

    return successors;
}

int main() {
    AdjacencyMatrix* adjMatrix = createMatrix(4);

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 2, 3);

    printf("Adjacency Matrix:\n");
    displayMatrix(adjMatrix);

    int node = 3;
    int* predecessors = getPredecessors(adjMatrix, node);

    printf("Predecessors of Node %d: ", node);
    for (int i = 0; i < adjMatrix->size; i++) {
        if (predecessors[i] != 0) {
            printf("%d ", predecessors[i]);
        }
    }
    printf("\n");

    free(predecessors);
    int* successors = getSuccessors(adjMatrix, node);

    printf("Successors of Node %d: ", node);
    for (int i = 0; successors[i] != 0; i++) {
        printf("%d ", successors[i]);
    }
    printf("\n");

    free(successors);
    destroyMatrix(adjMatrix);

    return 0;
}

