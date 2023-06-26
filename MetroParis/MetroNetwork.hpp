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

public:
    MetroNetwork();

    void addStation(std::shared_ptr<Node> station);
    void addEdge(std::shared_ptr<Edge> edge);

    std::shared_ptr<Node> getStation(int id);
    std::vector<std::shared_ptr<Edge>> getEdgesFromStation(int id);
    std::shared_ptr<Edge> getEdgeBetweenStations(int sourceId, int destinationId);

    void displayNetwork();
};

#endif // METRONETWORK_HPP
