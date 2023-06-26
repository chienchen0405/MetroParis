#include "Station.hpp"
#include "StationLine.hpp"
#include "MetroNetwork.hpp"
#include <memory>

void testStation() {
    // Create some nodes
    std::shared_ptr<Node> node1 = std::make_shared<Node>(1, "Station1", "Line1", 48.8566, 2.3522);
    std::shared_ptr<Node> node2 = std::make_shared<Node>(2, "Station2", "Line1", 48.8534, 2.3488);

    // Display node data
    std::cout << node1->getNodeData() << std::endl;
    std::cout << node2->getNodeData() << std::endl;

    // Create an edge
    Edge edge(node1, node2, 1.0, 2.0, 100, 10);

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
    auto edge1 = std::make_shared<Edge>(station1, station2, 1.0, 2.0, 100,10);
    auto edge2 = std::make_shared<Edge>(station2, station3, 1.5, 3.0, 100,10);

    // Add the edges to the network
    metroNetwork.addEdge(edge1);
    metroNetwork.addEdge(edge2);

    // Display the network
    metroNetwork.displayNetwork();
}


int main() {
    testStation();
    testStationLine();
    testMetroNetwork();
    return 0;
}
