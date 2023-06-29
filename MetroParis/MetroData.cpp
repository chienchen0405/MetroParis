#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "MetroNetwork.hpp"
#include "MetroData.hpp"
#include "Station.hpp"

void MetroData::readFromFile(const std::string& filename, MetroNetwork& network) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 1; // Track the line number for error reporting
    bool isFirstRow = true;
    while (std::getline(file, line)) {
        if (isFirstRow) {
            isFirstRow = false;
            continue;
        }

        std::istringstream iss(line);
        std::string token;
        std::getline(iss, token, ','); // Skip the first field

        // Read station IDs
        int curId = -1, nexId = -1;
        std::getline(iss, token, ',');
        try {
            curId = std::stoi(token);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing curId at line " << lineNumber << ": " << e.what() << std::endl;
            continue;
        }
        
        std::getline(iss, token, ',');
        try {
            nexId = std::stoi(token);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing nexId at line " << lineNumber << ": " << e.what() << std::endl;
            continue;
        }

        // Read edge parameters
        int distance = 0, travel_time = 0, capacity = 0;
        std::string line;

        std::getline(iss, token, ',');
        try {
            distance = std::stoi(token);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing distance at line " << lineNumber << ": " << e.what() << std::endl;
            continue;
        }

        std::getline(iss, token, ',');
        try {
            travel_time = std::stoi(token);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing travel_time at line " << lineNumber << ": " << e.what() << std::endl;
            continue;
        }

        std::getline(iss, token, ',');
        line = token;

        std::getline(iss, token, ',');
        try {
            capacity = std::stoi(token);
        } catch (const std::exception& e) {
            std::cerr << "Error parsing capacity at line " << lineNumber << ": " << e.what() << std::endl;
            continue;
        }

        // Read cur station names
        std::string curName, nexName;
        std::getline(iss, token, ',');
        curName = token;

        // Read latitudes and longitudes for cur
        std::string curGeoPoint;
        std::getline(iss, token, ',');
        std::string temp=token;
        std::getline(iss, token, ',');
        curGeoPoint = temp+","+token;
        
        // Skip the next column (cur_Geo Shape)
        std::getline(iss, token, ',');
        std::getline(iss, token, ',');
        std::getline(iss, token, ',');

        // Read nex station name
        std::getline(iss, token, ',');
        nexName = token;

        // Read latitudes and longitudes for destination
        std::string nexGeoPoint;
        std::getline(iss, token, ',');
        temp=token;
        std::getline(iss, token, ',');
        nexGeoPoint = temp+","+token;

        // Skip the next column (nex_Geo Shape)
        std::getline(iss, token, ',');

        // Read the principal column
        std::getline(iss, token, ',');
        bool isPrincipal = (token == "1");


        // Create nodes and edges
        std::shared_ptr<Node> curNode = std::make_shared<Node>(curId, curName, curGeoPoint);
        std::shared_ptr<Node> nexNode = std::make_shared<Node>(nexId, nexName, nexGeoPoint);
        std::shared_ptr<Edge> edge = std::make_shared<Edge>(curNode, nexNode, distance, travel_time, capacity, line);

        // Add nodes and edges to the network
        network.addStation(curNode);
        network.addStation(nexNode);
        network.addEdge(edge);

        // If the station is marked as principal, add it to the list of potential start/end stations
        if (isPrincipal) {
            network.addPotentialStartEndStation(curId);
        }
        
        lineNumber++; // Increment the line number
    }
    
    file.close();
    
}

void MetroData::writeToFile(const std::string& filename, const MetroNetwork& network) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to create file: " << filename << std::endl;
        return;
    }

    // Write the header row
    file << "EdgeNumber,Cur codeunique,Next codeunique,distance(Weight),travel_time,res_com,capacity,cur_name,cur_Geo Point,cur_Geo Shape,nex_name,cur_Geo Point,cur_Geo Shape,mode_,principal" << std::endl;

    // Write the data for each edge
    const std::set<std::shared_ptr<Edge>, MetroNetwork::EdgePtrComp>& edges = network.getAllEdges();
    for (const auto& edge : edges) {
        file << edge->getSource()->getId() << ","; // Cur codeunique
        file << edge->getDestination()->getId() << ","; // Next codeunique
        file << edge->getDistance() << ","; // distance(Weight)
        file << edge->getTravelTime() << ","; // travel_time
        file << edge->getLine() << ","; // res_com
        file << edge->getCapacity() << ","; // capacity
        file << edge->getSource()->getName() << ","; // cur_name
        file << edge->getSource()->getGeoPoint() << ","; // cur_Geo Point
        file << edge->getDestination()->getName() << ","; // nex_name
        file << edge->getDestination()->getGeoPoint() << ","; // cur_Geo Point
        file << "METRO,"; // mode_
        file << (network.isPotentialStartEndStation(edge->getSource()->getId()) ? "1" : "0"); // principal
        file << std::endl;
    }

    file.close();
}
