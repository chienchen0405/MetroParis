#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Node {
public:
    Node(int curNode, const std::string& curName, const std::string& curGeoPoint);
    std::string getNodeData() const;
    int getId() const;
    std::string getName() const;
    std::string getGeoPoint() const;

private:
    int id;
    std::string name;
    std::string geoPoint;
};

class Edge {
public:
    Edge(std::shared_ptr<Node> curNode, std::shared_ptr<Node> nexNode, double distance, double travelTime, int capacity, const std::string& line);
    std::string getEdgeData() const;
    int getCapacity() const;
    std::shared_ptr<Node> getSource() const;
    double getDistance() const;
    double getTravelTime() const;
    std::shared_ptr<Node> getDestination() const;
    std::string getLine() const;

    bool operator<(const Edge& other) const;

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
