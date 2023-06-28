#include<sstream>
#include "Station.hpp"

// Node function implementations
<<<<<<< HEAD
Node::Node(int nodeId, const std::string& nodeName, double nodeLatitude, double nodeLongitude)
    : id(nodeId), name(nodeName), latitude(nodeLatitude), longitude(nodeLongitude) {}
=======

// Constructor for the Node class
Node::Node(int nodeId, const std::string& nodeName, const std::string& nodeLine, double nodeLatitude, double nodeLongitude)
    : id(nodeId), name(nodeName), line(nodeLine), latitude(nodeLatitude), longitude(nodeLongitude) {}
>>>>>>> 3f12940aaa8f8987e82f15bb8ffd3a770851191d

// Function to get the string representation of the Node's data
std::string Node::getNodeData() const {
    std::ostringstream oss;
<<<<<<< HEAD
    oss << "Node ID: " << id << "\n";
    oss << "Node Name: " << name << "\n";
    oss << "Node Latitude: " << latitude << "\n";
    oss << "Node Longitude: " << longitude << "\n";
    return oss.str();
=======
    oss << "Node ID: " << id << "\n"; // Append the ID of the Node
    oss << "Node Name: " << name << "\n"; // Append the name of the Node
    oss << "Node Line: " << line << "\n"; // Append the line of the Node
    oss << "Node Latitude: " << latitude << "\n"; // Append the latitude of the Node
    oss << "Node Longitude: " << longitude << "\n"; // Append the longitude of the Node
    return oss.str(); // Return the string representation of the Node's data
>>>>>>> 3f12940aaa8f8987e82f15bb8ffd3a770851191d
}

// Function to get the ID of the Node
int Node::getId() const {
    return id; // Return the ID of the Node
}

// Function to get the name of the Node
std::string Node::getName() const {
    return name; // Return the name of the Node
}

<<<<<<< HEAD
=======
// Function to get the line of the Node
std::string Node::getLine() const {
    return line; // Return the line of the Node
}

// Function to get the latitude of the Node
>>>>>>> 3f12940aaa8f8987e82f15bb8ffd3a770851191d
double Node::getLatitude() const {
    return latitude; // Return the latitude of the Node
}

// Function to get the longitude of the Node
double Node::getLongitude() const {
    return longitude; // Return the longitude of the Node
}

// Edge function implementations
<<<<<<< HEAD
//Instead of raw pointers, consider using smart pointers,for the source and destination nodes in the Edge class.
//This will help manage memory more effectively removing nodes from the list and avoid potential memory leaks or dangling pointer issues.
Edge::Edge(std::shared_ptr<Node> sourceNode, std::shared_ptr<Node> destNode, double edgeDistance, double edgeTravelTime, int edgeCapacity, const std::string& edgeLine)
    : source(sourceNode), destination(destNode), distance(edgeDistance), travelTime(edgeTravelTime), capacity(edgeCapacity), line(edgeLine){}

=======

// Constructor for the Edge class
Edge::Edge(std::shared_ptr<Node> sourceNode, std::shared_ptr<Node> destNode, double edgeDistance, double edgeTravelTime, int edgeCapacity)
    : source(sourceNode), destination(destNode), distance(edgeDistance), travelTime(edgeTravelTime), capacity(edgeCapacity) {}
>>>>>>> 3f12940aaa8f8987e82f15bb8ffd3a770851191d

// Function to get the string representation of the Edge's data
std::string Edge::getEdgeData() const {
    std::ostringstream oss;
<<<<<<< HEAD
    oss << "Source Node ID: " << source->getId() << "\n";
    oss << "Destination Node ID: " << destination->getId() << "\n";
    oss << "Distance: " << distance << "\n";
    oss << "Travel Time: " << travelTime << "\n";
    oss << "Capacity: " << capacity << "\n";
    oss << "Line: "<<line<<"\n";
    return oss.str();
=======
    oss << "Source Node ID: " << source->getId() << "\n"; // Append the ID of the source Node
    oss << "Destination Node ID: " << destination->getId() << "\n"; // Append the ID of the destination Node
    oss << "Distance: " << distance << "\n"; // Append the distance of the Edge
    oss << "Travel Time: " << travelTime << "\n"; // Append the travel time of the Edge
    oss << "Capacity: " << capacity << "\n"; // Append the capacity of the Edge
    return oss.str(); // Return the string representation of the Edge's data
>>>>>>> 3f12940aaa8f8987e82f15bb8ffd3a770851191d
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

<<<<<<< HEAD
std::string Edge::getLine() const {
    return line;
}

std::vector<std::shared_ptr<Node>> nodes;
std::vector<Edge> edges;
=======
std::vector<std::shared_ptr<Node>> nodes;  // Vector to store shared pointers to Node objects
std::vector<Edge> edges;  // Vector to store Edge objects
>>>>>>> 3f12940aaa8f8987e82f15bb8ffd3a770851191d
