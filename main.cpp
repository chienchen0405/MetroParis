#include "Station.h"
#include <memory>

void Task1() {
    // Create some nodes
    std::shared_ptr<Node> node1 = std::make_shared<Node>(1, "Station1", "Line1", 48.8566, 2.3522);
    std::shared_ptr<Node> node2 = std::make_shared<Node>(2, "Station2", "Line1", 48.8534, 2.3488);

    // Display node data
    std::cout << node1->getNodeData() << std::endl;
    std::cout << node2->getNodeData() << std::endl;

    // Create an edge
    Edge edge(node1, node2, 1.0, 2.0, 100);

    // Display edge data
    std::cout << edge.getEdgeData() << std::endl;
}

int main() {
    Task1();
    return 0;
}
