#ifndef TASK3_H
#define TASK3_H

#include "task1.h"
#include <map>
#include <vector>
#include <memory>

class AdjacencyMatrix {
public:
    void addEdge(std::shared_ptr<Node> source, std::shared_ptr<Node> destination, double distance, double travelTime, int capacity);
    std::shared_ptr<Edge> getEdge(int sourceId, int destinationId);
    void displayMatrix();
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename);
    int getSize() const;

private:
    std::map<int, std::map<int, std::shared_ptr<Edge> > > matrix;
    std::vector<std::shared_ptr<Node>> nodes;
    std::vector<std::shared_ptr<Edge>> edges;
};

class AdjacencyList {
public:
    void addEdge(std::shared_ptr<Node> source, std::shared_ptr<Node> destination, double distance, double travelTime, int capacity);
    std::shared_ptr<Edge> getEdge(int sourceId, int destinationId);
    void displayList();
    void readFromFile(const std::string& filename);
    void writeToFile(const std::string& filename);
    int getSize() const;

private:
    std::map<int, std::vector<std::shared_ptr<Edge> > > list;
    std::vector<std::shared_ptr<Node>> nodes;
    std::vector<std::shared_ptr<Edge>> edges;
};

#endif // TASK3_H
