#include "task1.h"
#include "task3.h"

// AdjacencyMatrix class implementation

AdjacencyMatrix::AdjacencyMatrix(int size) {
    this->size = size;

    // Allocate memory for the matrix
    matrix = new Edge**[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new Edge*[size];
        for (int j = 0; j < size; j++) {
            matrix[i][j] = nullptr; // Initialize all elements with null pointer
        }
    }
}

AdjacencyMatrix::~AdjacencyMatrix() {
    // Deallocate memory for the matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            delete matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
}

void AdjacencyMatrix::addEdge(Node* source, Node* destination, double distance, double travelTime, int capacity) {
    // Create a new Edge object
    Edge* edge = new Edge(source, destination, distance, travelTime, capacity);

    // Set the edge in the matrix
    matrix[source->getId()][destination->getId()] = edge;
}

Edge* AdjacencyMatrix::getEdge(Node* source, Node* destination) {
    // Retrieve the edge from the matrix
    return matrix[source->getId()][destination->getId()];
}

void AdjacencyMatrix::displayMatrix() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] != nullptr) {
                std::cout << "Edge exists between Node " << i << " and Node " << j << ": Yes" << std::endl;
                matrix[i][j]->displayEdge();
            }
            else {
                std::cout << "Edge exists between Node " << i << " and Node " << j << ": No" << std::endl;
            }
            std::cout << std::endl;
        }
    }
}

// AdjacencyList class implementation

AdjacencyList::AdjacencyList(int size) {
    this->size = size;

    // Resize the vector to hold 'size' number of elements
    list.resize(size);
}

AdjacencyList::~AdjacencyList() {
    // Deallocate memory for each linked list
    for (int i = 0; i < size; i++) {
        for (size_t j = 0; j < list[i].size(); j++) {
            delete list[i][j];
        }
    }
}

void AdjacencyList::addEdge(Node* source, Node* destination, double distance, double travelTime, int capacity) {
    // Create a new Edge object
    Edge* edge = new Edge(source, destination, distance, travelTime, capacity);

    // Add the edge to the source node's list
    list[source->getId()].push_back(edge);
}

Edge* AdjacencyList::getEdge(Node* source, Node* destination) {
    // Search for the edge in the source node's list
    for (Edge* edge : list[source->getId()]) {
        if (edge->getDestination() == destination) {
            return edge;
        }
    }
    return nullptr; // Edge not found
}

void AdjacencyList::displayList() {
    for (int i = 0; i < size; i++) {
        for (size_t j = 0; j < list[i].size(); j++) {
            Edge* edge = list[i][j];
            std::cout << "Source Node: " << edge->getSource()->getName() << std::endl;
            std::cout << "Destination Node: " << edge->getDestination()->getName() << std::endl;
            std::cout << "Distance: " << edge->getDistance() << " meters" << std::endl;
            std::cout << "Travel Time: " << edge->getTravelTime() << " minutes" << std::endl;
            std::cout << "Capacity: " << edge->getCapacity() << " passengers" << std::endl;
            std::cout << std::endl;
        }
    }
}