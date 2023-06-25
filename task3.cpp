#include "task1.h"
#include "task3.h"
#include <map>
#include <memory>
#include <iostream>

// AdjacencyMatrix class implementation

void AdjacencyMatrix::addEdge(Node* source, Node* destination, double distance, double travelTime, int capacity) {
    int sourceId = source->getId();
    int destinationId = destination->getId();

    std::shared_ptr<Edge> edge = std::make_shared<Edge>(source, destination, distance, travelTime, capacity);
    matrix[sourceId][destinationId] = edge;
}

std::shared_ptr<Edge> AdjacencyMatrix::getEdge(int sourceId, int destinationId) {
    return matrix[sourceId][destinationId];
}

void AdjacencyMatrix::displayMatrix() {
    for (const auto& sourcePair : matrix) {
        for (const auto& destinationPair : sourcePair.second) {
            std::shared_ptr<Edge> edge = destinationPair.second;
            std::cout << "Source Node ID: " << edge->getSource()->getId() << std::endl;
            std::cout << "Destination Node ID: " << edge->getDestination()->getId() << std::endl;
            std::cout << "Distance: " << edge->getDistance() << std::endl;
            std::cout << "Travel Time: " << edge->getTravelTime() << std::endl;
            std::cout << "Capacity: " << edge->getCapacity() << std::endl;
            std::cout << std::endl;
        }
    }
}

// AdjacencyList class implementation

void AdjacencyList::addEdge(Node* source, Node* destination, double distance, double travelTime, int capacity) {
    int sourceId = source->getId();

    std::shared_ptr<Edge> edge = std::make_shared<Edge>(source, destination, distance, travelTime, capacity);
    list[sourceId].push_back(edge);
}

std::shared_ptr<Edge> AdjacencyList::getEdge(int sourceId, int destinationId) {
    for (const auto& edge : list[sourceId]) {
        if (edge->getDestination()->getId() == destinationId) {
            return edge;
        }
    }
    return nullptr;
}

void AdjacencyList::displayList() {
    for (const auto& pair : list) {
        for (const auto& edge : pair.second) {
            std::cout << "Source Node ID: " << edge->getSource()->getId() << std::endl;
            std::cout << "Destination Node ID: " << edge->getDestination()->getId() << std::endl;
            std::cout << "Distance: " << edge->getDistance() << std::endl;
            std::cout << "Travel Time: " << edge->getTravelTime() << std::endl;
            std::cout << "Capacity: " << edge->getCapacity() << std::endl;
            std::cout << std::endl;
        }
    }
}
