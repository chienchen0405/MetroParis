#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Node {
public:
    Node(int nodeId, const std::string& nodeName, const std::string& nodeLine, double nodeLatitude, double nodeLongitude);
    std::string getNodeData() const;
    int getId() const;
    std::string getName() const;
    std::string getLine() const;
    double getLatitude() const;
    double getLongitude() const;

private:
    int id;
    std::string name;
    std::string line;
    double latitude;
    double longitude;
};

class Edge {
public:
    Edge(std::shared_ptr<Node> sourceNode, std::shared_ptr<Node> destNode, double edgeDistance, double edgeTravelTime, int edgeCapacity, double edgeWeight);
    std::string getEdgeData() const;
    int getCapacity() const;
    std::shared_ptr<Node> getSource() const;
    double getDistance() const;
    double getTravelTime() const;
    std::shared_ptr<Node> getDestination() const;
    double getWeight() const;

private:
    std::shared_ptr<Node> source;
    std::shared_ptr<Node> destination;
    double distance;
    double travelTime;
    int capacity;
    double weight;
};

extern std::vector<std::shared_ptr<Node>> nodes;
extern std::vector<Edge> edges;

#endif // STATION_H
