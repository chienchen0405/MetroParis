#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "MetroNetwork.hpp"
#include "MetroData.hpp"

// Constructor
MetroNetwork::MetroNetwork() {}

// Add a station to the network
void MetroNetwork::addStation(std::shared_ptr<Node> station) {
    if (station == nullptr) {
        std::cerr << "Error: Attempted to add a null station to the network." << std::endl;
        return;
    }
    if (nodes.find(station->getId()) != nodes.end()) {
        std::cerr << "Error: A station with ID " << station->getId() << " already exists." << std::endl;
        return;
    }
    nodes[station->getId()] = station;
    // Debug print statement
    std::cout << "Added station: " << station->getNodeData() << std::endl;
}


// Add an edge to the network
void MetroNetwork::addEdge(std::shared_ptr<Edge> edge) {
    if (edge == nullptr) {
        std::cerr << "Error: Attempted to add a null edge to the network." << std::endl;
        return;
    }
    int sourceId = edge->getSource()->getId();
    int destinationId = edge->getDestination()->getId();
    if (adjacencyMatrix.find(sourceId) != adjacencyMatrix.end() && adjacencyMatrix[sourceId].find(destinationId) != adjacencyMatrix[sourceId].end()) {
        std::cerr << "Error: An edge between stations with IDs " << sourceId << " and " << destinationId << " already exists." << std::endl;
        return;
    }
    // Add to adjacency list
    adjacencyList[sourceId].push_back(edge);

    // Add to reverse adjacency list
    reverseAdjacencyList[destinationId].push_back(edge);

    // Add to adjacency matrix
    adjacencyMatrix[sourceId][destinationId] = edge;

    // Create the reverse edge
    std::shared_ptr<Edge> reverseEdge = std::make_shared<Edge>(edge->getDestination(), edge->getSource(), edge->getDistance(), edge->getTravelTime(), edge->getCapacity(), edge->getLine());

    // Add the reverse edge to the adjacency list, reverse adjacency list, and adjacency matrix
    adjacencyList[destinationId].push_back(reverseEdge);
    reverseAdjacencyList[sourceId].push_back(reverseEdge);
    adjacencyMatrix[destinationId][sourceId] = reverseEdge;

    // Debug print statement
    std::cout << "Added edge: " << edge->getEdgeData() << std::endl;
    std::cout << "Added reverse edge: " << reverseEdge->getEdgeData() << std::endl;
}

// Add a potential start/end station
void MetroNetwork::addPotentialStartEndStation(int id) {
    potentialStartEndStations.push_back(id);
}

bool MetroNetwork::isPotentialStartEndStation(int id) const {
    return std::find(potentialStartEndStations.begin(), potentialStartEndStations.end(), id) != potentialStartEndStations.end();
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

//this is for direct graph

//// Get the predecessors of a node
//// Each edge in the vector for a node N is an edge leading to N.
//std::vector<std::shared_ptr<Node>> MetroNetwork::getPredecessors(int id) {
//    std::vector<std::shared_ptr<Node>> predecessors;
//    for (const auto& edge : reverseAdjacencyList[id]) {
//        predecessors.push_back(edge->getSource());
//    }
//    return predecessors;
//}
//
//
//
//// Get the successors of a node
//// the set of all nodes with an edge from N
//std::vector<std::shared_ptr<Node>> MetroNetwork::getSuccessors(int id) {
//    std::vector<std::shared_ptr<Node>> successors;
//    for (const auto& edge : adjacencyList[id]) {
//        successors.push_back(edge->getDestination());
//    }
//    return successors;
//}

// Get the predecessors of a node
std::vector<std::shared_ptr<Node>> MetroNetwork::getPredecessors(int id) {
    std::vector<std::shared_ptr<Node>> predecessors;
    for (const auto& edge : adjacencyList[id]) {
        predecessors.push_back(edge->getDestination());
    }
    return predecessors;
}


// Get the successors of a node
std::vector<std::shared_ptr<Node>> MetroNetwork::getSuccessors(int id) {
    return getPredecessors(id);
}

void MetroNetwork::analyzeNetwork() {
    for (const auto& nodePair : this->getNodes()) {
        int id = nodePair.first;
        if (this->getPredecessors(id).size() == 1 && std::find(potentialStartEndStations.begin(), potentialStartEndStations.end(), id) != potentialStartEndStations.end()) {
            potentialStartEndStations.push_back(id);
        }
        if (this->getSuccessors(id).size() == 1 && std::find(potentialStartEndStations.begin(), potentialStartEndStations.end(), id) != potentialStartEndStations.end()) {
            potentialStartEndStations.push_back(id);
        }
    }
}

std::set<std::shared_ptr<Edge>, MetroNetwork::EdgePtrComp> MetroNetwork::getAllEdges() const {
    std::set<std::shared_ptr<Edge>, MetroNetwork::EdgePtrComp> allEdges;
    for (const auto& pair : adjacencyList) {
        for (const auto& edge : pair.second) {
            allEdges.insert(edge);
        }
    }
    return allEdges;
}

void updateCurrentNodeAndLine(std::vector<std::shared_ptr<Node>>& nodes, std::shared_ptr<Node>& currentNode, Line& line, bool isPredecessor) {
    if (!nodes.empty()) {
        currentNode = nodes[0];
        if (isPredecessor) {
            line.insertHeadStation(currentNode);
        } else {
            line.insertEndStation(currentNode);
        }
    }
}

//Line MetroNetwork::getRecommend(int startNodeId) {
//    auto startNodeIter = nodes.find(startNodeId);
//
//    if (startNodeIter == nodes.end()) {
//        throw std::invalid_argument("Start node is not found in the network!");
//    }
//
//    std::shared_ptr<Node> currentNode = startNodeIter->second;
//    Line line;
//
//    for (int i = 0; i < 3 && currentNode; i++) {
//        auto predecessors = getPredecessors(currentNode->getId());
//        auto successors = getSuccessors(currentNode->getId());
//
//        updateCurrentNodeAndLine(predecessors, currentNode, line, true);
//        updateCurrentNodeAndLine(successors, currentNode, line, false);
//    }
//
//    return line;
//}
