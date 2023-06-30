#include "StationLine.hpp"
#include "LinkedList.hpp"
#include "Station.hpp"
#include <iostream>

// Function to insert a station at the beginning of the line
void Line::insertHeadStation(std::shared_ptr<Node> station) {
    stations.insertAtBeginning(station); // Insert the station at the beginning of the line
}

// Function to insert a station at the end of the line
void Line::insertEndStation(std::shared_ptr<Node> station) {
    stations.insertAtEnd(station); // Insert the station at the end of the line
}

// Function to remove and return the station at the beginning of the line
std::shared_ptr<Node> Line::popHeadStation() {
    return stations.popFromBeginning(); // Remove and return the station from the beginning of the line
}

// Function to remove and return the station at the end of the line
std::shared_ptr<Node> Line::popEndStation() {
    return stations.popFromEnd(); // Remove and return the station from the end of the line
}

// Function to search for a station in the line
bool Line::searchStation(std::shared_ptr<Node> station) {
    return stations.searchCell(station); // Search for the station in the line
}

// Function to destroy the line iteratively
void Line::destroyLineIterative() {
    stations.destroyListIterative(); // Destroy the line iteratively
}

// Function to destroy the line recursively
void Line::destroyLineRecursive() {
    stations.destroyListRecursive(); // Destroy the line recursively
}

// Function to display the line
void Line::displayLine() {
    std::shared_ptr<Cell<Node>> current = stations.getHead(); // Get the head of the line
    while (current != nullptr) { // Iterate through the line until the end
        std::cout << current->value->getNodeData() << std::endl; // Print the data of the current station
        current = current->next; // Move to the next station
    }
}

std::shared_ptr<Cell<Node>> Line::getHead() {
    return stations.getHead();
}

