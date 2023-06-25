#include "task1.h"
#include "task3.h"
#include <iostream>

int main() {
    // Create some nodes
    Node node1(1, "Node1", "Line1", 0.0, 0.0);
    Node node2(2, "Node2", "Line2", 1.0, 1.0);
    Node node3(3, "Node3", "Line3", 2.0, 2.0);

    // Create an adjacency matrix and add some edges
    AdjacencyMatrix matrix;
    matrix.addEdge(&node1, &node2, 1.0, 1.0, 1);
    matrix.addEdge(&node2, &node3, 2.0, 2.0, 2);

    // Display the matrix
    std::cout << "Adjacency Matrix:" << std::endl;
    matrix.displayMatrix();

    // Create an adjacency list and add some edges
    AdjacencyList list;
    list.addEdge(&node1, &node2, 1.0, 1.0, 1);
    list.addEdge(&node2, &node3, 2.0, 2.0, 2);

    // Display the list
    std::cout << "Adjacency List:" << std::endl;
    list.displayList();

    return 0;
}
