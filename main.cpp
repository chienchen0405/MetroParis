#include "task1.h"

int main() {
    // Create nodes
    Node node1("Node 1", "Line A", 0.0, 0.0);
    Node node2("Node 2", "Line B", 1.0, 1.0);

    // Create an edge with capacity
    Edge edge(&node1, &node2, 1000.0, 10.0, 200);

    // Display node and edge information
    node1.displayNode();
    std::cout << std::endl;
    node2.displayNode();
    std::cout << std::endl;
    edge.displayEdge();
    std::cout << std::endl;

    // Get the capacity of the edge
    int edgeCapacity = edge.getCapacity();
    std::cout << "Edge Capacity: " << edgeCapacity << " passengers" << std::endl;

    return 0;
}