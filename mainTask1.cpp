#include "task1.h"
int main() {
    // Create example nodes
    Node node1(1, "Node 1", "Line A", 1.23, 4.56);
    Node node2(2, "Node 2", "Line B", 7.89, 0.12);

    // Display node information
    node1.displayNode();
    node2.displayNode();

    // Create example edge
    Edge edge(&node1, &node2, 10.5, 15.2, 100);

    // Display edge information
    edge.displayEdge();

    return 0;
}