#include "task1.h"

Node::Node(const std::string& nodeName, const std::string& nodeLine, double nodeLatitude, double nodeLongitude)
    : name(nodeName), line(nodeLine), latitude(nodeLatitude), longitude(nodeLongitude) {
    // Initialize any additional parameters here
}

void Node::displayNode() const {
    std::cout << "Node Name: " << name << std::endl;
    std::cout << "Line: " << line << std::endl;
    std::cout << "Latitude: " << latitude << std::endl;
    std::cout << "Longitude: " << longitude << std::endl;
    // Display any additional parameters here
}

std::string Node::getName() const {
    return name;
}

std::string Node::getLine() const {
    return line;
}

double Node::getLatitude() const {
    return latitude;
}

double Node::getLongitude() const {
    return longitude;
}

Edge::Edge(Node* sourceNode, Node* destNode, double edgeDistance, double edgeTravelTime, int edgeCapacity)
    : source(sourceNode), destination(destNode), distance(edgeDistance), travelTime(edgeTravelTime), capacity(edgeCapacity) {
    // Initialize any additional parameters here
}

void Edge::displayEdge() const {
    std::cout << "Source Node: " << source->getName() << std::endl;
    std::cout << "Destination Node: " << destination->getName() << std::endl;
    std::cout << "Distance: " << distance << " meters" << std::endl;
    std::cout << "Travel Time: " << travelTime << " minutes" << std::endl;
    std::cout << "Capacity: " << capacity << " passengers" << std::endl;
    // Display any additional parameters here
}

int Edge::getCapacity() const {
    return capacity;
}