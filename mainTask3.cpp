#include "task1.h"
#include "task3.h"

int main() {
    // Create some nodes
    Node node1(1, "Node 1", "Line A", 10.0, 20.0);
    Node node2(2, "Node 2", "Line B", 30.0, 40.0);
    Node node3(3, "Node 3", "Line C", 50.0, 60.0);

    // Create an adjacency matrix
    AdjacencyMatrix matrix(3);

    // Add edges to the matrix
    matrix.addEdge(&node1, &node2, 100.0, 60.0, 200);
    matrix.addEdge(&node2, &node3, 150.0, 90.0, 300);
    matrix.addEdge(&node3, &node1, 200.0, 120.0, 400);

    // Display the matrix
    matrix.displayMatrix();

    // Create an adjacency list
    AdjacencyList list(3);

    // Add edges to the list
    list.addEdge(&node1, &node2, 100.0, 60.0, 200);
    list.addEdge(&node2, &node3, 150.0, 90.0, 300);
    list.addEdge(&node3, &node1, 200.0, 120.0, 400);

    // Display the list
    list.displayList();

    return 0;
}