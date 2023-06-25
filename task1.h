#ifndef TASK1_H
#define TASK1_H

#include <iostream>
#include <string>

class Node {
private:
    int id;
    std::string name;
    std::string line;
    double latitude;
    double longitude;

public:
    // Constructor
    Node(int nodeId, const std::string& nodeName, const std::string& nodeLine, double nodeLatitude, double nodeLongitude);

    // Display node information
    void displayNode() const;

    // Get the ID of the node
    int getId() const;

    // Get the name of the node
    std::string getName() const;

    // Get the line of the node
    std::string getLine() const;

    // Get the latitude of the node
    double getLatitude() const;

    // Get the longitude of the node
    double getLongitude() const;
};

class Edge {
private:
    Node* source;
    Node* destination;
    double distance;
    double travelTime;
    int capacity;

public:
    // Constructor
    Edge(Node* sourceNode, Node* destNode, double edgeDistance, double edgeTravelTime, int edgeCapacity);

    // Display edge information
    void displayEdge() const;

    // Get the capacity of the edge
    int getCapacity() const;

    // Get the source node of the edge
    Node* getSource() const;

    // Get the distance of the edge
    double getDistance() const;

    // Get the travel time of the edge
    double getTravelTime() const;

    // Get the destination node of the edge
    Node* getDestination() const;
};

#endif // TASK1_H