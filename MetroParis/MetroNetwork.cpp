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
std::vector<std::shared_ptr<Edge>> MetroNetwork::getEdgesFromStation(int id) const {
    try {
        return adjacencyList.at(id);
    } catch (std::out_of_range& e) {
        std::cerr << "No edges found for station with ID " << id << std::endl;
        return std::vector<std::shared_ptr<Edge>>();  // Return an empty vector
    }
}


// Get the edge between two stations by their ids
std::shared_ptr<Edge> MetroNetwork::getEdgeBetweenStations(int sourceId, int destinationId) {
    return adjacencyMatrix[sourceId][destinationId];
}

// Display the info using iterative list
void MetroNetwork::displayInfoList() {
    for (const auto& nodePair : nodes) {
        std::cout << "Station: " << nodePair.second->getNodeData() << std::endl;
        std::cout << "Connected to: ";
        for (const auto& edge : adjacencyList[nodePair.first]) {
            std::cout << edge->getDestination()->getNodeData() << " ";
            std::cout << "Edge data: " << edge->getEdgeData() << std::endl;
        }
        std::cout << std::endl;
    }
}

// Display the info using iterative matrix
void MetroNetwork::displayInfoMatrix() {
    for (const auto& row : adjacencyMatrix) {
        for (const auto& cell : row.second) {
            if (cell.second) {
                std::cout << "Edge from station " << row.first
                          << " to station " << cell.first
                          << ": " << cell.second->getEdgeData() << std::endl;
            }
        }
    }
}

// Display the adjacency matrix
void MetroNetwork::displayAdjacencyMatrix() {
    for (const auto& row : adjacencyMatrix) {
        for (const auto& cell : row.second) {
            if (cell.second) {
                std::cout << "Edge from station " << row.first
                          << " to station " << cell.first
                          << ": " << cell.second->getEdgeData() << std::endl;
            } else {
                std::cout << "No edge from station " << row.first
                          << " to station " << cell.first << std::endl;
            }
        }
    }
}

std::map<int, std::shared_ptr<Node>> MetroNetwork::getNodes() const {
    return nodes;
}

// Get the predecessors of a node
std::vector<std::shared_ptr<Node>> MetroNetwork::getPredecessors(int id) {
    std::vector<std::shared_ptr<Node>> predecessors;
    for (const auto& nodePair : nodes) {
        for (const auto& edge : adjacencyList[nodePair.first]) {
            if (edge->getDestination()->getId() == id) {
                predecessors.push_back(nodePair.second);
            }
        }
    }
    return predecessors;
}


// Get the successors of a node
std::vector<std::shared_ptr<Node>> MetroNetwork::getSuccessors(int id) {
    // For an undirected graph, the successors are the same as the predecessors
    return getPredecessors(id);
}





