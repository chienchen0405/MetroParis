#include<sstream>
#include "Station.hpp"

// Node function implementations
Node::Node(int curNode, const std::string& curName, const std::string& curGeoPoint)
    : id(curNode), name(curName), geoPoint(curGeoPoint) {}


// Function to get the string representation of the Node's data
std::string Node::getNodeData() const {
    std::ostringstream oss;
    oss << "Node ID: " << id << "\n"; // Append the ID of the Node
    oss << "Node Name: " << name << "\n"; // Append the name of the Node
    oss << "Node GeoPoint: " << geoPoint << "\n"; // Append the GeoPoint of the Node
    return oss.str(); // Return the string representation of the Node's data
}

// Function to get the ID of the Node
int Node::getId() const {
    return id; // Return the ID of the Node
}

// Function to get the name of the Node
std::string Node::getName() const {
    return name; // Return the name of the Node
}

// Function to get the GeoPoint of the Node
std::string Node::getGeoPoint() const {
    return geoPoint; // Return the GeoPoint of the Node
}

std::string Node::toCSV() const {
    std::ostringstream oss;
    oss << id << "," << name << "," << geoPoint;
    return oss.str();
}

// Edge function implementations

Edge::Edge(std::shared_ptr<Node> curNode, std::shared_ptr<Node> nexNode, double distance, double travelTime, int capacity, const std::string& res_com)
    : source(curNode), destination(nexNode), distance(distance), travelTime(travelTime), capacity(capacity), line(res_com){}


// Function to get the string representation of the Edge's data
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

// Function to get the capacity of the Edge
int Edge::getCapacity() const {
    return capacity; // Return the capacity of the Edge
}

// Function to get the source Node of the Edge
std::shared_ptr<Node> Edge::getSource() const {
    return source; // Return the source Node of the Edge
}

// Function to get the distance of the Edge
double Edge::getDistance() const {
    return distance; // Return the distance of the Edge
}

// Function to get the travel time of the Edge
double Edge::getTravelTime() const {
    return travelTime; // Return the travel time of the Edge
}

// Function to get the destination Node of the Edge
std::shared_ptr<Node> Edge::getDestination() const {
    return destination; // Return the destination Node of the Edge
}

std::string Edge::getLine() const {
    return line;
}

bool Edge::operator<(const Edge& other) const {
        if (this->getSource()->getId() == other.getSource()->getId()) {
            return this->getDestination()->getId() < other.getDestination()->getId();
        } else {
            return this->getSource()->getId() < other.getSource()->getId();
        }
}

std::vector<std::shared_ptr<Node>> nodes;
std::vector<Edge> edges;
