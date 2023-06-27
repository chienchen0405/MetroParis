#include "MetroNetwork.hpp"

// Constructor
MetroNetwork::MetroNetwork() {}

// Add a station to the network
void MetroNetwork::addStation(std::shared_ptr<Node> station) {
    if (station == nullptr) {
        std::cerr << "Error: Attempted to add a null station to the network." << std::endl;
        return;
    }
    nodes[station->getId()] = station;
}


// Add an edge to the network
void MetroNetwork::addEdge(std::shared_ptr<Edge> edge) {
    if (edge == nullptr) {
        std::cerr << "Error: Attempted to add a null edge to the network." << std::endl;
        return;
    }
    int sourceId = edge->getSource()->getId();
    int destinationId = edge->getDestination()->getId();

    // Add to adjacency list
    adjacencyList[sourceId].push_back(edge);

    // Add to reverse adjacency list
    reverseAdjacencyList[destinationId].push_back(edge);

    // Add to adjacency matrix
    adjacencyMatrix[sourceId][destinationId] = edge;
}

// Get a station by its id
std::shared_ptr<Node> MetroNetwork::getStation(int id) {
    if (nodes.find(id) == nodes.end()) {
        std::cerr << "Error: No station found with ID " << id << "." << std::endl;
        return nullptr;
    }
    return nodes[id];
}

// Get all edges from a station by its id
std::vector<std::shared_ptr<Edge>> MetroNetwork::getEdgesFromStation(int id) const {
    if (adjacencyList.find(id) == adjacencyList.end()) {
        std::cerr << "Error: No edges found for station with ID " << id << "." << std::endl;
        return std::vector<std::shared_ptr<Edge>>();  // Return an empty vector
    }
    return adjacencyList.at(id);
}


// Get the edge between two stations by their ids
std::shared_ptr<Edge> MetroNetwork::getEdgeBetweenStations(int sourceId, int destinationId) {
    if (adjacencyMatrix.find(sourceId) == adjacencyMatrix.end() || adjacencyMatrix[sourceId].find(destinationId) == adjacencyMatrix[sourceId].end()) {
        std::cerr << "Error: No edge found between stations with IDs " << sourceId << " and " << destinationId << "." << std::endl;
        return nullptr;
    }
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

// Display the adjacency matrix from read file.
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
// Each edge in the vector for a node N is an edge leading to N.
std::vector<std::shared_ptr<Node>> MetroNetwork::getPredecessors(int id) {
    std::vector<std::shared_ptr<Node>> predecessors;
    for (const auto& edge : reverseAdjacencyList[id]) {
        predecessors.push_back(edge->getSource());
    }
    return predecessors;
}



// Get the successors of a node
// the set of all nodes with an edge from N
std::vector<std::shared_ptr<Node>> MetroNetwork::getSuccessors(int id) {
    std::vector<std::shared_ptr<Node>> successors;
    for (const auto& edge : adjacencyList[id]) {
        successors.push_back(edge->getDestination());
    }
    return successors;
}






