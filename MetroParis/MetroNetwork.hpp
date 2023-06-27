#ifndef METRONETWORK_HPP
#define METRONETWORK_HPP

#include "Station.hpp"
#include <map>
#include <vector>
#include <memory>

class MetroNetwork {
private:
    std::map<int, std::shared_ptr<Node>> nodes;
    std::map<int, std::vector<std::shared_ptr<Edge>>> adjacencyList;
    std::map<int, std::map<int, std::shared_ptr<Edge>>> adjacencyMatrix;
    
    //reverseAdjacencyList is a map from node IDs to vectors of edges. Each edge in the vector for a node N is an edge leading to N. This allows to get the predecessors of a node in O(1) time by simply looking up the node in reverseAdjacencyList.
    std::map<int, std::vector<std::shared_ptr<Edge>>> reverseAdjacencyList;

public:
    MetroNetwork();

    void addStation(std::shared_ptr<Node> station);
    void addEdge(std::shared_ptr<Edge> edge);

    std::shared_ptr<Node> getStation(int id);
    std::vector<std::shared_ptr<Edge>> getEdgesFromStation(int id) const;
    std::shared_ptr<Edge> getEdgeBetweenStations(int sourceId, int destinationId);
    
    std::map<int, std::shared_ptr<Node>> getNodes() const;

    void displayInfoList();
    void displayInfoMatrix();
    
    void displayAdjacencyMatrix();
    
    // Get the predecessors of a node
    std::vector<std::shared_ptr<Node>> getPredecessors(int id);

    // Get the successors of a node
    std::vector<std::shared_ptr<Node>> getSuccessors(int id);
};

#endif // METRONETWORK_HPP
