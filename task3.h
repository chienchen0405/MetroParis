#ifndef TASK3_H
#define TASK3_H

#include "task1.h"
#include <map>
#include <vector>
#include <memory>

class AdjacencyMatrix {
private:
    std::map<int, std::map<int, std::shared_ptr<Edge> > > matrix;

public:
    void addEdge(Node* source, Node* destination, double distance, double travelTime, int capacity);
    std::shared_ptr<Edge> getEdge(int sourceId, int destinationId);
    void displayMatrix();
};

class AdjacencyList {
private:
    std::map<int, std::vector<std::shared_ptr<Edge> > > list;

public:
    void addEdge(Node* source, Node* destination, double distance, double travelTime, int capacity);
    std::shared_ptr<Edge> getEdge(int sourceId, int destinationId);
    void displayList();
};

#endif // TASK3_H
