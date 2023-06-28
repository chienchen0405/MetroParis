#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Node {
public:
    Node(int nodeId, const std::string& nodeName, double nodeLatitude, double nodeLongitude);
    std::string getNodeData() const;
    int getId() const;
    std::string getName() const;
    double getLatitude() const;
    double getLongitude() const;

private:
    int id;
    std::string name;
    double latitude;
    double longitude;
};

class Edge {
public:
    Edge(std::shared_ptr<Node> sourceNode, std::shared_ptr<Node> destNode, double edgeDistance, double edgeTravelTime, int edgeCapacity,const std::string& edgeLine);
    std::string getEdgeData() const;
    int getCapacity() const;
    std::shared_ptr<Node> getSource() const;
    double getDistance() const;
    double getTravelTime() const;
    std::shared_ptr<Node> getDestination() const;
    std::string getLine() const;

private:
    std::shared_ptr<Node> source;
    std::shared_ptr<Node> destination;
    double distance;
    double travelTime;
    int capacity;
    std::string line;
};

extern std::vector<std::shared_ptr<Node>> nodes;
extern std::vector<Edge> edges;

#endif // STATION_H
