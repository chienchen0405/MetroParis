#include "MetroNetwork.hpp"

// Constructor
MetroNetwork::MetroNetwork() {}

// Add a station to the network
void MetroNetwork::addStation(std::shared_ptr<Node> station) {
    nodes[station->getId()] = station;
}

// Add an edge to the network
void MetroNetwork::addEdge(std::shared_ptr<Edge> edge) {
    int sourceId = edge->getSource()->getId();
    int destinationId = edge->getDestination()->getId();

    // Add to adjacency list
    adjacencyList[sourceId].push_back(edge);

    // Add to adjacency matrix
    adjacencyMatrix[sourceId][destinationId] = edge;
}

// Get a station by its id
std::shared_ptr<Node> MetroNetwork::getStation(int id) {
    return nodes[id];
}

// Get all edges from a station by its id
std::vector<std::shared_ptr<Edge>> MetroNetwork::getEdgesFromStation(int id) {
    return adjacencyList[id];
}

// Get the edge between two stations by their ids
std::shared_ptr<Edge> MetroNetwork::getEdgeBetweenStations(int sourceId, int destinationId) {
    return adjacencyMatrix[sourceId][destinationId];
}

// Display the network
void MetroNetwork::displayNetwork() {
    for (const auto& nodePair : nodes) {
        std::cout << "Station: " << nodePair.second->getNodeData() << std::endl;
        std::cout << "Connected to: ";
        for (const auto& edge : adjacencyList[nodePair.first]) {
            std::cout << edge->getDestination()->getNodeData() << " ";
        }
        std::cout << std::endl;
    }
}

