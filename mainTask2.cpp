#include "task1.h"
#include "task2.h"

int main() {
    // Create nodes
    Node node1(1, "Node 1", "Line A", 0.0, 0.0);
    Node node2(2, "Node 2", "Line B", 1.0, 1.0);

    // Create edges
    Edge edge1(&node1, &node2, 1000.0, 10.0, 200);
    Edge edge2(&node2, &node1, 1000.0, 10.0, 200);

    // Create a linked list of edges
    Cell<Edge>* list = nullptr;
    Cell<Edge>* cell1 = createCell(&edge1);
    Cell<Edge>* cell2 = createCell(&edge2);
    insertAtBeginning(list, cell1);
    insertAtEnd(list, cell2);

    // Display the list of edges
    displayList(list);

    // Pop a cell from the beginning of the list
    Cell<Edge>* poppedCell = popFromBeginning(list);
    if (poppedCell != nullptr) {
        std::cout << "Popped Cell: ";
        poppedCell->value->displayEdge();
        std::cout << std::endl;
        delete poppedCell;
    }

    // Search for a cell in the list
    bool exists = searchCell(list, &edge2);
    std::cout << "Edge 2 exists in the list: " << (exists ? "Yes" : "No") << std::endl;

    // Destroy the list using an iterative algorithm
    destroyListIterative(list);

    // Display the list after destruction
    displayList(list);

    return 0;
}