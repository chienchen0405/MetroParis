#include "Station.hpp"
#include "StationLine.hpp"

#include "MetroNetwork.hpp"
#include "ShortestPath.hpp"
#include "MetroData.hpp"

#include <iostream>
#include <memory>
#include <unistd.h>
#include <limits.h>
#include <sstream>
#include <fstream>



//deposite
//basically the task 1 and task2 we work together last week to know the basic knowledge, and establish the environment for each member
//the task 3 and task 4 also task 5 ,member Mingfu Fu, create a demo code to test, and me , leader of group1, Yutao Chen, implement all these code into project, make them readable and esay-access.and other two group member add the footnotes and make sure it`s understandable for others.
//later we will add more comment on these code to explain everything we face problem and test for function.
//due to now the entire work is not too much actually just some tasks of part1, is not exact contributions for each person, basically due to there are some member they haven`t knowledge of coding indiviudally to finished a task, so at the beginning i think it`s better to work together, this week we will work more time individually, and it will have more clear contributions for each person.



// void testReadFromFile() {
//     MetroNetwork network;
//     MetroData metroData;

//     // Read from file
//     metroData.readFromFile("test.csv", network);

//     // Write to file
//     metroData.writeToFile("test_ouput.csv", network);

//     // Display the info using iterative list
//     //network.displayInfoList();

//     // Display the info using iterative matrix
//     //network.displayInfoMatrix();

//     // Display the adjacency matrix
//     network.displayAdjacencyMatrix();
// }


void testShortestPath() {
    // Create a MetroData object to read from the CSV file
    MetroData metroData;

    // Create a MetroNetwork object to hold the network data
    MetroNetwork network;

    // Read from the CSV file into the MetroNetwork object
    metroData.readFromFile("test.csv", network);

    // Create a ShortestPath object to find shortest paths in the network
    ShortestPath shortestPath;

    // Find the shortest path from a source node to a destination node
    int sourceId = 101033; // Change this to your actual source node ID
    int destinationId = 103035; // Change this to your actual destination node ID

    auto result = shortestPath.findShortestPath(network, sourceId, destinationId);

    // Open an output file stream
    std::ofstream outfile("output.csv");

    // Write the header to the file
    outfile << "Station Name,Latitude,Longitude,Metro Line\n";

    // Create a Line object and populate it with the stations from the shortest path
    Line line;
    for (const auto& node : result.second) {
        line.insertEndStation(node);
    }

    std::shared_ptr<Cell<Node>> current = line.getHead(); // Get the head of the line
    std::shared_ptr<Cell<Node>> next = nullptr;

    while (current != nullptr) { // Iterate through the line until the end
        std::string geoPoint = current->value->getGeoPoint();
        size_t commaPos = geoPoint.find(",");
        
        std::string latitude = geoPoint.substr(1, commaPos - 1); // Start at 1 to skip the first quote
        std::string longitude = geoPoint.substr(commaPos + 1, geoPoint.length() - commaPos - 2); // Subtract 2 to skip the last quote

        std::string metroLine;

        // Get the next node in the line, if it exists
        next = current->next != nullptr ? current->next : nullptr;

        if (next != nullptr) {
            auto edge = network.getEdgeBetweenStations(current->value->getId(), next->value->getId());
            if (edge) { // Check if edge is not null
                metroLine = edge->getLine();
            }
        }
        
        outfile << current->value->getName() << "," << latitude << "," << longitude << "," << metroLine << "\n";

        // Move to the next station
        current = next;
    }

    // Close the file stream
    outfile.close();
}






int main() {
    //testReadFromFile();
    testShortestPath();
    return 0;
}
