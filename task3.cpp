#include "task3.h"
#include <fstream>
#include <iostream>

// AdjacencyMatrix class implementation

void AdjacencyMatrix::addEdge(std::shared_ptr<Node> source, std::shared_ptr<Node> destination, double distance, double travelTime, int capacity) {
    int sourceId = source->getId();
    int destinationId = destination->getId();

    std::shared_ptr<Edge> edge = std::make_shared<Edge>(source, destination, distance, travelTime, capacity);
    matrix[sourceId][destinationId] = edge;
    edges.push_back(edge);  // Add the edge to the vector of edges
}

std::shared_ptr<Edge> AdjacencyMatrix::getEdge(int sourceId, int destinationId) {
    return matrix[sourceId][destinationId];
}

int AdjacencyMatrix::getSize() const {
    return static_cast<int>(nodes.size());
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

void AdjacencyMatrix::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    int numNodes, numEdges;
    file >> numNodes >> numEdges;

    // Create Node objects
    for (int i = 0; i < numNodes; i++) {
        nodes.push_back(std::make_shared<Node>(i, "Node" + std::to_string(i), "Line" + std::to_string(i), 0.0, 0.0));
    }

    // Create Edge objects and add them to the adjacency matrix
    for (int i = 0; i < numEdges; i++) {
        int sourceId, destinationId, value;
        file >> sourceId >> destinationId >> value;

        addEdge(nodes[sourceId], nodes[destinationId], value, 0, 0);
    }

    file.close();
}

void AdjacencyMatrix::writeToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    file << nodes.size() << " " << edges.size() << "\n";

    for (const auto& edge : edges) {
        file << edge->getSource()->getId() << " " << edge->getDestination()->getId() << " " << edge->getDistance() << "\n";
    }

    file.close();
}

// AdjacencyList class implementation

void AdjacencyList::addEdge(std::shared_ptr<Node> source, std::shared_ptr<Node> destination, double distance, double travelTime, int capacity) {
    int sourceId = source->getId();

    std::shared_ptr<Edge> edge = std::make_shared<Edge>(source, destination,distance, travelTime, capacity);
    list[sourceId].push_back(edge);
    edges.push_back(edge);  // Add the edge to the vector of edges
}

std::shared_ptr<Edge> AdjacencyList::getEdge(int sourceId, int destinationId) {
    for (const auto& edge : list[sourceId]) {
        if (edge->getDestination()->getId() == destinationId) {
            return edge;
        }
    }
    return nullptr;
}

int AdjacencyList::getSize() const {
    return static_cast<int>(nodes.size());
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

void AdjacencyList::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    int numNodes, numEdges;
    file >> numNodes >> numEdges;

    // Create Node objects
    for (int i = 0; i < numNodes; i++) {
        nodes.push_back(std::make_shared<Node>(i, "Node" + std::to_string(i), "Line" + std::to_string(i), 0.0, 0.0));
    }

    // Create Edge objects and add them to the adjacency list
    for (int i = 0; i < numEdges; i++) {
        int sourceId, destinationId, value;
        file >> sourceId >> destinationId >> value;

        addEdge(nodes[sourceId], nodes[destinationId], value, 0, 0);
    }

    file.close();
}

void AdjacencyList::writeToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    file << nodes.size() << " " << edges.size() << "\n";

    for (const auto& edge : edges) {
        file << edge->getSource()->getId() << " " << edge->getDestination()->getId() << " " << edge->getDistance() << "\n";
    }

    file.close();
}
