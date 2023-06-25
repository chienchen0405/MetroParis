#ifndef TASK3_H
#define TASK3_H

#include "task1.h"
#include <vector>

class AdjacencyMatrix {
private:
    int size;
    Edge*** matrix;

public:
    AdjacencyMatrix(int size);
    ~AdjacencyMatrix();
    void addEdge(Node* source, Node* destination, double distance, double travelTime, int capacity);
    Edge* getEdge(Node* source, Node* destination);
    void displayMatrix();
};

class AdjacencyList {
private:
    int size;
    std::vector<std::vector<Edge*> > list;

public:
    AdjacencyList(int size);
    ~AdjacencyList();
    void addEdge(Node* source, Node* destination, double distance, double travelTime, int capacity);
    Edge* getEdge(Node* source, Node* destination);
    void displayList();
};

#endif // TASK3_H