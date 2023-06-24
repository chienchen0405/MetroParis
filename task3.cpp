#include <stdio.h>
#include <stdlib.h>

// 定义邻接矩阵结构体
typedef struct {
    int** matrix;  // 存储矩阵的二维数组
    int size;  // 矩阵的大小
} AdjacencyMatrix;

// 创建一个 size × size 的矩阵，并用空指针初始化所有元素
AdjacencyMatrix* createMatrix(int size) {
    AdjacencyMatrix* adjMatrix = (AdjacencyMatrix*)malloc(sizeof(AdjacencyMatrix));
    adjMatrix->size = size;

    // 分配存储矩阵的二维数组内存
    adjMatrix->matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        adjMatrix->matrix[i] = (int*)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++) {
            adjMatrix->matrix[i][j] = NULL;  // 用空指针初始化所有元素
        }
    }

    return adjMatrix;
}

// 在节点 from 和 to 之间添加一条边，其中 from 和 to 是作为参数给出的
void addEdge(AdjacencyMatrix* adjMatrix, int from, int to) {
    adjMatrix->matrix[from][to] = 1;
}

// 检索存储在行 row，列 col 的值
int getValue(AdjacencyMatrix* adjMatrix, int row, int col) {
    return adjMatrix->matrix[row][col];
}

// 销毁一个邻接矩阵（内存释放）
void destroyMatrix(AdjacencyMatrix* adjMatrix) {
    for (int i = 0; i < adjMatrix->size; i++) {
        free(adjMatrix->matrix[i]);
    }
    free(adjMatrix->matrix);
    free(adjMatrix);
}

// 显示一个邻接矩阵
void displayMatrix(AdjacencyMatrix* adjMatrix) {
    for (int i = 0; i < adjMatrix->size; i++) {
        for (int j = 0; j < adjMatrix->size; j++) {
            printf("%d ", adjMatrix->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 3;  // 矩阵的大小

    AdjacencyMatrix* adjMatrix = createMatrix(size);
    addEdge(adjMatrix, 1, 2);

    int value = getValue(adjMatrix, 1, 2);
    printf("存储在行1，列2的值为：%d\n", value);

    displayMatrix(adjMatrix);

    destroyMatrix(adjMatrix);

    return 0;
}
