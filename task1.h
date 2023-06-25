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
    Node(int nodeId, const std::string& nodeName, const std::string& nodeLine, double nodeLatitude, double nodeLongitude);
    void displayNode() const;
    int getId() const;
    std::string getName() const;
    std::string getLine() const;
    double getLatitude() const;
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
    Edge(Node* sourceNode, Node* destNode, double edgeDistance, double edgeTravelTime, int edgeCapacity);
    void displayEdge() const;
    int getCapacity() const;
    Node* getSource() const;
    double getDistance() const;
    double getTravelTime() const;
    Node* getDestination() const;
};

#endif // TASK1_H