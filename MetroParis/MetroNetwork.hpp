#ifndef METRONETWORK_HPP
#define METRONETWORK_HPP

#include "Station.hpp"
#include <map>
#include <vector>
#include <memory>
#include <set>
#include <memory>


class MetroNetwork {
private:
    std::map<int, std::shared_ptr<Node>> nodes;
    std::map<int, std::vector<std::shared_ptr<Edge>>> adjacencyList;
    std::map<int, std::map<int, std::shared_ptr<Edge>>> adjacencyMatrix;
    std::map<int, std::vector<std::shared_ptr<Edge>>> reverseAdjacencyList;
    std::vector<int> potentialStartEndStations;
    
public:
    MetroNetwork();

    void addStation(std::shared_ptr<Node> station);
    void addEdge(std::shared_ptr<Edge> edge);
    void addPotentialStartEndStation(int id);
    bool isPotentialStartEndStation(int id) const;

    std::shared_ptr<Node> getStation(int id);
    std::vector<std::shared_ptr<Edge>> getEdgesFromStation(int id) const;
    std::shared_ptr<Edge> getEdgeBetweenStations(int sourceId, int destinationId);
    
    std::map<int, std::shared_ptr<Node>> getNodes() const;

    void displayInfoList();
    void displayInfoMatrix();
    
    void displayAdjacencyMatrix();
    
    std::vector<std::shared_ptr<Node>> getPredecessors(int id);
    std::vector<std::shared_ptr<Node>> getSuccessors(int id);
    
    void analyzeNetwork();
    
    struct EdgePtrComp {
        bool operator()(const std::shared_ptr<Edge>& lhs, const std::shared_ptr<Edge>& rhs) const {
            return *lhs < *rhs;
        }
    };
    
    std::set<std::shared_ptr<Edge>, EdgePtrComp> getAllEdges() const;
};

#endif // METRONETWORK_HPP
