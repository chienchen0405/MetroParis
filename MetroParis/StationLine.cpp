#include "StationLine.hpp"
#include "LinkedList.hpp"
#include "Station.hpp"
#include <iostream>

void Line::insertHeadStation(std::shared_ptr<Node> station) {
    stations.insertAtBeginning(station);
}

void Line::insertEndStation(std::shared_ptr<Node> station) {
    stations.insertAtEnd(station);
}

std::shared_ptr<Node> Line::popHeadStation() {
    return stations.popFromBeginning();
}

std::shared_ptr<Node> Line::popEndStation() {
    return stations.popFromEnd();
}

bool Line::searchStation(std::shared_ptr<Node> station) {
    return stations.searchCell(station);
}

void Line::destroyLineIterative() {
    stations.destroyListIterative();
}

void Line::destroyLineRecursive() {
    stations.destroyListRecursive();
}

void Line::displayLine() {
    std::shared_ptr<Cell<Node>> current = stations.getHead();
    while (current != nullptr) {
        std::cout << current->value->getNodeData() << std::endl;
        current = current->next;
    }
}
