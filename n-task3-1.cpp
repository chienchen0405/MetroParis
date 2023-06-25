#include <stdio.h>
#include <stdlib.h>

// Define the adjacency matrix structure
typedef struct {
    int** matrix;  // 2D array to store the matrix
    int size;  // Size of the matrix
} AdjacencyMatrix;

// Create a size x size matrix and initialize all elements with NULL
AdjacencyMatrix* createMatrix(int size) {
    AdjacencyMatrix* adjMatrix = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
    adjMatrix->size = size;

    // Allocate memory for the 2D array to store the matrix
    adjMatrix->matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        adjMatrix->matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            adjMatrix->matrix[i][j] = NULL;  // Initialize all elements with NULL
        }
    }

    return adjMatrix;
}

// Add an edge between nodes 'from' and 'to'
void addEdge(AdjacencyMatrix* adjMatrix, int from, int to) {
    adjMatrix->matrix[from][to] = 1;
}

// Retrieve the value stored at the given row and column
int getValue(AdjacencyMatrix* adjMatrix, int row, int col) {
    return adjMatrix->matrix[row][col];
}

// Destroy an adjacency matrix (free memory)
void destroyMatrix(AdjacencyMatrix* adjMatrix) {
    for (int i = 0; i < adjMatrix->size; i++) {
        free(adjMatrix->matrix[i]);
    }
    free(adjMatrix->matrix);
    free(adjMatrix);
}

// Display an adjacency matrix
void displayMatrix(AdjacencyMatrix* adjMatrix) {
    for (int i = 0; i < adjMatrix->size; i++) {
        for (int j = 0; j < adjMatrix->size; j++) {
            printf("%d ", adjMatrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 3;  // Size of the matrix

    AdjacencyMatrix* adjMatrix = createMatrix(size);
    addEdge(adjMatrix, 1, 2);

    int value = getValue(adjMatrix,1, 2);
    printf("存储在行1，列2的值为：%d\n", value);

    displayMatrix(adjMatrix);

    destroyMatrix(adjMatrix);

    return 0;
}
