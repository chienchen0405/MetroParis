#include<sstream>
#include "Station.hpp"

// Node function implementations
Node::Node(int nodeId, const std::string& nodeName, double nodeLatitude, double nodeLongitude)
    : id(nodeId), name(nodeName), latitude(nodeLatitude), longitude(nodeLongitude) {}

std::string Node::getNodeData() const {
    std::ostringstream oss;
    oss << "Node ID: " << id << "\n";
    oss << "Node Name: " << name << "\n";
    oss << "Node Latitude: " << latitude << "\n";
    oss << "Node Longitude: " << longitude << "\n";
    return oss.str();
}

int Node::getId() const {
    return id;
}

std::string Node::getName() const {
    return name;
}

double Node::getLatitude() const {
    return latitude;
}

double Node::getLongitude() const {
    return longitude;
}

// Edge function implementations
//Instead of raw pointers, consider using smart pointers,for the source and destination nodes in the Edge class.
//This will help manage memory more effectively removing nodes from the list and avoid potential memory leaks or dangling pointer issues.
Edge::Edge(std::shared_ptr<Node> sourceNode, std::shared_ptr<Node> destNode, double edgeDistance, double edgeTravelTime, int edgeCapacity, const std::string& edgeLine)
    : source(sourceNode), destination(destNode), distance(edgeDistance), travelTime(edgeTravelTime), capacity(edgeCapacity), line(edgeLine){}


std::string Edge::getEdgeData() const {
    std::ostringstream oss;
    oss << "Source Node ID: " << source->getId() << "\n";
    oss << "Destination Node ID: " << destination->getId() << "\n";
    oss << "Distance: " << distance << "\n";
    oss << "Travel Time: " << travelTime << "\n";
    oss << "Capacity: " << capacity << "\n";
    oss << "Line: "<<line<<"\n";
    return oss.str();
}

int Edge::getCapacity() const {
    return capacity;
}

std::shared_ptr<Node> Edge::getSource() const {
    return source;
}

double Edge::getDistance() const {
    return distance;
}

double Edge::getTravelTime() const {
    return travelTime;
}

std::shared_ptr<Node> Edge::getDestination() const {
    return destination;
}

std::string Edge::getLine() const {
    return line;
}

std::vector<std::shared_ptr<Node>> nodes;
std::vector<Edge> edges;
