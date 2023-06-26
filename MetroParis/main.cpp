#include "Station.hpp"
#include "StationLine.hpp"
#include "MetroNetwork.hpp"
#include "MetroData.hpp"
#include <memory>
#include <iostream>
#include <unistd.h>
#include <limits.h>

//deposite
//basically the task 1 and task2 we work together last week to know the basic knowledge, and establish the environment for each member
//the task 3 and task 4 also task 5 ,member Mingfu Fu, create a demo code to test, and me , leader of group1, Yutao Chen, implement all these code into project, make them readable and esay-access.and other two group member add the footnotes and make sure it`s understandable for others.
//later we will add more comment on these code to explain everything we face problem and test for function.
//due to now the entire work is not too much actually just some tasks of part1, is not exact contributions for each person, basically due to there are some member they haven`t knowledge of coding indiviudally to finished a task, so at the beginning i think it`s better to work together, this week we will work more time individually, and it will have more clear contributions for each person.

void testStation() {
    // Create some nodes
    std::shared_ptr<Node> node1 = std::make_shared<Node>(1, "Station1", "Line1", 48.8566, 2.3522);
    std::shared_ptr<Node> node2 = std::make_shared<Node>(2, "Station2", "Line1", 48.8534, 2.3488);

    // Display node data
    std::cout << node1->getNodeData() << std::endl;
    std::cout << node2->getNodeData() << std::endl;

    // Create an edge
    Edge edge(node1, node2, 1.0, 2.0, 100);

    // Display edge data
    std::cout << edge.getEdgeData() << std::endl;
}

void testStationLine() {
    // Create a Line object
    Line line;

    // Create some Node objects
    std::shared_ptr<Node> station1 = std::make_shared<Node>(1, "Station 1", "Line 1", 48.8566, 2.3522);
    std::shared_ptr<Node> station2 = std::make_shared<Node>(2, "Station 2", "Line 1", 48.8576, 2.3532);
    std::shared_ptr<Node> station3 = std::make_shared<Node>(3, "Station 3", "Line 1", 48.8586, 2.3542);

    // Insert stations at the beginning of the line
    line.insertHeadStation(station1);
    line.insertHeadStation(station2);

    // Insert a station at the end of the line
    line.insertEndStation(station3);

    // Display the line
    line.displayLine();

    // Pop a station from the beginning of the line
    std::shared_ptr<Node> poppedStation = line.popHeadStation();
    if (poppedStation != nullptr) {
        std::cout << "Popped station from the beginning: " << poppedStation->getNodeData() << std::endl;
    }

    // Pop a station from the end of the line
    poppedStation = line.popEndStation();
    if (poppedStation != nullptr) {
        std::cout << "Popped station from the end: " << poppedStation->getNodeData() << std::endl;
    }

    // Search for a station in the line
    bool found = line.searchStation(station1);
    std::cout << "Station 1 found in line: " << (found ? "Yes" : "No") << std::endl;

    // Destroy the line
    line.destroyLineIterative();
}

void testMetroNetwork() {
    // Create a MetroNetwork
    MetroNetwork metroNetwork;

    // Create some stations
    auto station1 = std::make_shared<Node>(1, "Station1", "Line1", 48.8566, 2.3522);
    auto station2 = std::make_shared<Node>(2, "Station2", "Line1", 48.853, 2.35);
    auto station3 = std::make_shared<Node>(3, "Station3", "Line2", 48.860, 2.344);

    // Add the stations to the network
    metroNetwork.addStation(station1);
    metroNetwork.addStation(station2);
    metroNetwork.addStation(station3);

    // Create some edges
    auto edge1 = std::make_shared<Edge>(station1, station2, 1.0, 2.0, 100);
    auto edge2 = std::make_shared<Edge>(station2, station3, 1.5, 3.0, 100);

    // Add the edges to the network
    metroNetwork.addEdge(edge1);
    metroNetwork.addEdge(edge2);

    // Display the network
    std::cout << "Adjacency List:" << std::endl;
    metroNetwork.displayInfoList();
    
    // Display the network as an adjacency matrix
    std::cout << "Adjacency Matrix:" << std::endl;
    metroNetwork.displayInfoMatrix();
}

void testMetroData() {
    MetroNetwork network;
    MetroData data;

    int maxId = data.getMaxStationId("Graph_list.csv");
    for (int i = 1; i <= maxId; i++) {
        auto station = std::make_shared<Node>(i, "Node" + std::to_string(i), "Line" + std::to_string(i), 0.0, 0.0);
        network.addStation(station);
    }

    data.readFromFile("Graph_list.csv", network);
    data.writeToFile("Graph_list_output.csv", network);
}


int location(){
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "Current working directory: " << cwd << std::endl;
    } else {
        std::cerr << "getcwd() error" << std::endl;
        return 1;
    }
    return 0;
}

void testGetMaxStationId() {
    MetroData data;
    int maxId = data.getMaxStationId("Graph_list.csv");
    std::cout << "Max station ID: " << maxId << std::endl;
}

void testPredecessorsAndSuccessors() {
    // Create a new MetroNetwork
    MetroNetwork metroNetwork;

    // Add stations to the network
    for (int i = 1; i <= 5; i++) {
        metroNetwork.addStation(std::make_shared<Node>(i));
    }

    // Add edges to the network
    for (int i = 1; i < 5; i++) {
        metroNetwork.addEdge(std::make_shared<Edge>(metroNetwork.getStation(i), metroNetwork.getStation(i + 1), i));
    }

    // Get and print the predecessors and successors of a node
    int nodeId = 3;
    std::vector<std::shared_ptr<Node>> predecessors = metroNetwork.getPredecessors(nodeId);
    std::vector<std::shared_ptr<Node>> successors = metroNetwork.getSuccessors(nodeId);

    std::cout << "Predecessors of node " << nodeId << ": ";
    for (const auto& node : predecessors) {
        std::cout << node->getId() << " ";
    }
    std::cout << std::endl;

    std::cout << "Successors of node " << nodeId << ": ";
    for (const auto& node : successors) {
        std::cout << node->getId() << " ";
    }
    std::cout << std::endl;
}


int main() {
    //testStation();
    //testStationLine();
    //testMetroNetwork();
    //location();
    //testMetroData();
    //testGetMaxStationId();
    testPredecessorsAndSuccessors();
    return 0;
}
