#include <stdio.h>
#include <stdlib.h>

// �����ڽӾ���ṹ��
typedef struct {
    int** matrix;  // �洢����Ķ�ά����
    int size;  // ����Ĵ�С
} AdjacencyMatrix;

// ����һ�� size �� size �ľ��󣬲��ÿ�ָ���ʼ������Ԫ��
AdjacencyMatrix* createMatrix(int size) {
    AdjacencyMatrix* adjMatrix = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
    adjMatrix->size = size;

    // ����洢����Ķ�ά�����ڴ�
    adjMatrix->matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        adjMatrix->matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            adjMatrix->matrix[i][j] = NULL;  // �ÿ�ָ���ʼ������Ԫ��
        }
    }

    return adjMatrix;
}

// �ڽڵ� from �� to ֮�����һ���ߣ����� from �� to ����Ϊ����������
void addEdge(AdjacencyMatrix* adjMatrix, int from, int to) {
    adjMatrix->matrix[from][to] = 1;
}

// �����洢���� row���� col ��ֵ
int getValue(AdjacencyMatrix* adjMatrix, int row, int col) {
    return adjMatrix->matrix[row][col];
}

// ����һ���ڽӾ����ڴ��ͷţ�
void destroyMatrix(AdjacencyMatrix* adjMatrix) {
    for (int i = 0; i < adjMatrix->size; i++) {
        free(adjMatrix->matrix[i]);
    }
    free(adjMatrix->matrix);
    free(adjMatrix);
}

// ��ʾһ���ڽӾ���
void displayMatrix(AdjacencyMatrix* adjMatrix) {
    for (int i = 0; i < adjMatrix->size; i++) {
        for (int j = 0; j < adjMatrix->size; j++) {
            printf("%d ", adjMatrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 3;  // ����Ĵ�С

    AdjacencyMatrix* adjMatrix = createMatrix(size);
    addEdge(adjMatrix, 1, 2);

    int value = getValue(adjMatrix, 1, 2);
    printf("�洢����1����2��ֵΪ��%d\n", value);

    displayMatrix(adjMatrix);

    destroyMatrix(adjMatrix);

    return 0;
}
