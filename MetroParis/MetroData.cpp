#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include "MetroNetwork.hpp"
#include "MetroData.hpp"

// Function to sanitize input
std::string MetroData::sanitizeInput(const std::string& input) {
    std::string output;
    for (char c : input) {
        if (c >= 0 && c <= 127) {  // only allow ASCII characters
            output += c;
        }
    }
    return output;
}

// Define the readFromFile function
void MetroData::readFromFile(const std::string& filename, MetroNetwork& network) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::string line;
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
        int sourceId = -1, destId = -1;
        std::getline(iss, token, ',');
        sourceId = std::stoi(token);
        std::getline(iss, token, ',');
        destId = std::stoi(token);

        // Read edge parameters
        int distance = 0, travel_time = 0, capacity = 0;
        std::string line;
        std::getline(iss, token, ',');
        distance = std::stoi(token);
        std::getline(iss, token, ',');
        travel_time = std::stoi(token);
        std::getline(iss, token, ',');
        line = token;
        std::getline(iss, token, ',');
        capacity = std::stoi(token);

        // Read station names
        std::string sourceName, destName;
        std::getline(iss, token, ',');
        sourceName = token;

        // Read latitudes and longitudes for source
        double sourceLat = 0, sourceLong = 0, destLat = 0, destLong = 0;
        std::getline(iss, token, ',');
        std::cerr<<token;
        token = sanitizeInput(token);
        sourceLat=convertDMSToDecimal(token);
        if (sourceLat == -1) {
            std::cerr << "Invalid latitude: " << token << std::endl;
            continue;
        }
        
        std::getline(iss, token, ',');
        std::cerr<<token;
        token = sanitizeInput(token);
        sourceLong=convertDMSToDecimal(token);
        if (sourceLong == -1) {
            std::cerr << "Invalid longitude: " << token << std::endl;
            continue;
        }
        
        //Read destination name
        std::getline(iss, token, ',');
        destName = token;
        
        //Read latitudes and longitudes for destination
        
        std::getline(iss, token, ',');
        std::cerr<<token;
        token = sanitizeInput(token);
        destLat=convertDMSToDecimal(token);
        if (destLat == -1) {
            std::cerr << "Invalid longitude: " << token << std::endl;
            continue;
        }
        
        std::getline(iss, token, ',');
        std::cerr<<token;
        token = sanitizeInput(token);
        destLong=convertDMSToDecimal(token);
        if (destLong == -1) {
            std::cerr << "Invalid longitude: " << token << std::endl;
            continue;
        }
        
        // Create nodes and edges
        std::shared_ptr<Node> sourceNode = std::make_shared<Node>(sourceId, sourceName, sourceLat, sourceLong);
        std::shared_ptr<Node> destNode = std::make_shared<Node>(destId, destName, destLat, destLong);
        std::shared_ptr<Edge> edge = std::make_shared<Edge>(sourceNode, destNode, distance, travel_time, capacity, line);

        // Add nodes and edges to the network
        network.addStation(sourceNode);
        network.addStation(destNode);
        network.addEdge(edge);
    }
}





void MetroData::writeToFile(const std::string& filename, const MetroNetwork& network) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    // Write the header line to the file
    file << "source ID,destination ID,distance,travel_time,Line,source_name,source_lai,source_long,dies_name,des_lai,des_long\n";

    for (const auto& nodePair : network.getNodes()) {
        auto edges = network.getEdgesFromStation(nodePair.first);
        if (edges.empty()) {
            std::cerr << "No edges found for station with ID " << nodePair.first << "." << std::endl;
            continue;
        }

        for (const auto& edge : edges) {
            // Get the source and destination nodes
            auto source = edge->getSource();
            auto destination = edge->getDestination();

            // Write the edge and node data to the file
            file << source->getId() << ","
                 << destination->getId() << ","
                 << edge->getDistance() << ","
                 << edge->getTravelTime() << ","
                 << edge->getLine() << ","
                 << source->getName() << ","
                 << source->getLatitude() << ","
                 << source->getLongitude() << ","
                 << destination->getName() << ","
                 << destination->getLatitude() << ","
                 << destination->getLongitude() << "\n";
        }
    }
}


//This function reads the CSV file line by line, extracts the source ID from each line, and keeps track of the maximum source ID found. It returns the maximum source ID when it's done.
// and added to the MetroNetwork
int MetroData::getMaxStationId(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return -1;
    }

    std::string line;
    int maxId = -1;
    bool isFirstRow = true;
    while (std::getline(file, line)) {
        if (isFirstRow) {
            isFirstRow = false;
            continue;
        }

        std::istringstream iss(line);
        std::string token;
        // Get the second and third fields in each line
        std::getline(iss, token, ','); // Skip the first field
        for (int i = 0; i < 2; i++) {
            if (std::getline(iss, token, ',')) {
                try {
                    int id = std::stoi(token);
                    if (id > maxId) {
                        maxId = id;
                    }
                } catch (std::invalid_argument& e) {
                    std::cerr << "Invalid argument in line: " << line << std::endl;
                    break;
                } catch (std::out_of_range& e) {
                    std::cerr << "Out of range in line: " << line << std::endl;
                    break;
                }
            }
        }
    }
    return maxId;
}

double MetroData::convertDMSToDecimal(const std::string &coordinator) {
    std::size_t degreePos = coordinator.find(static_cast<char>(176));
    std::size_t minutePos = coordinator.find(static_cast<char>(39));
    std::size_t secondPos = coordinator.find(static_cast<char>(34));
    
    if (degreePos == std::string::npos || minutePos == std::string::npos || secondPos == std::string::npos) {
        throw std::invalid_argument("Invalid format: Expected format is d°m′s″ [cardinal direction]");
    }

    std::string degreesStr = coordinator.substr(0, degreePos);
    std::string minutesStr = coordinator.substr(degreePos+2, minutePos-degreePos-2);
    std::string secondsStr = coordinator.substr(minutePos+2, secondPos-minutePos-2);

    // Ignore the cardinal direction
    std::size_t directionPos = secondPos + 2;
    while (directionPos < coordinator.size() && std::isspace(coordinator[directionPos])) {
        ++directionPos;
    }
    if (directionPos < coordinator.size()) {
        secondsStr = coordinator.substr(minutePos+2, directionPos-minutePos-2);
    }

    double degrees, minutes, seconds;

    try {
        degrees = std::stod(degreesStr);
        minutes = std::stod(minutesStr);
        seconds = std::stod(secondsStr);
    } catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << '\n';
        throw;
    } catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << '\n';
        throw;
    }

    double decimal = degrees + minutes/60.0 + seconds/3600.0;

    // If the cardinal direction is 'S' or 'W', make the coordinate negative
    if (directionPos < coordinator.size() && (coordinator[directionPos] == 'S' || coordinator[directionPos] == 'W')) {
        decimal = -decimal;
    }

    return decimal;
}
