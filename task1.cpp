#include "task1.h"

// Node function implementations
Node::Node(int nodeId, const std::string& nodeName, const std::string& nodeLine, double nodeLatitude, double nodeLongitude)
    : id(nodeId), name(nodeName), line(nodeLine), latitude(nodeLatitude), longitude(nodeLongitude) {}

void Node::displayNode() const {
    std::cout << "Node ID: " << id << std::endl;
    std::cout << "Node Name: " << name << std::endl;
    std::cout << "Node Line: " << line << std::endl;
    std::cout << "Node Latitude: " << latitude << std::endl;
    std::cout << "Node Longitude: " << longitude << std::endl;
}

int Node::getId() const {
    return id;
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

// Edge function implementations
Edge::Edge(Node* sourceNode, Node* destNode, double edgeDistance, double edgeTravelTime, int edgeCapacity)
    : source(sourceNode), destination(destNode), distance(edgeDistance), travelTime(edgeTravelTime), capacity(edgeCapacity) {}

void Edge::displayEdge() const {
    std::cout << "Source Node ID: " << source->getId() << std::endl;
    std::cout << "Destination Node ID: " << destination->getId() << std::endl;
    std::cout << "Distance: " << distance << std::endl;
    std::cout << "Travel Time: " << travelTime << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
}

int Edge::getCapacity() const {
    return capacity;
}

Node* Edge::getSource() const {
    return source;
}

double Edge::getDistance() const {
    return distance;
}

double Edge::getTravelTime() const {
    return travelTime;
}

Node* Edge::getDestination() const {
    return destination;
}