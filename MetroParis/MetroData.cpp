#include <fstream>
#include <sstream>
#include "MetroNetwork.hpp"
#include "MetroData.hpp"

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
        std::vector<std::string> tokens;
        std::string token;
        // Ignore the first field in each line
        std::getline(iss, token, ',');
        while (std::getline(iss, token, ',')) {
            tokens.push_back(token);
        }

        // Print out the tokens for debugging
        for (const auto& t : tokens) {
            std::cout << t << " ";
        }
        std::cout << std::endl;

        // Skip the first token if it's an empty string
        size_t startIndex = tokens[0].empty() ? 1 : 0;

        if (tokens.size() < startIndex + 3) {
            std::cerr << "Error reading line: " << line << std::endl;
            continue;
        }

        try {
            int sourceId = std::stoi(tokens[startIndex]);
            int destinationId = std::stoi(tokens[startIndex + 1]);
            double distance = std::stod(tokens[startIndex + 2]);

            auto source = network.getStation(sourceId);
            auto destination = network.getStation(destinationId);
            if (!source || !destination) {
                std::cerr << "Invalid node ID in line: " << line << std::endl;
                continue;
            }

            auto edge = std::make_shared<Edge>(source, destination, distance, 0, 0);
            network.addEdge(edge);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument in line: " << line << std::endl;
            continue;
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of range in line: " << line << std::endl;
            continue;
        }
    }
}






void MetroData::writeToFile(const std::string& filename, const MetroNetwork& network) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    for (const auto& nodePair : network.getNodes()) {
        for (const auto& edge : network.getEdgesFromStation(nodePair.first)) {
            file << edge->getSource()->getId() << ","
                 << edge->getDestination()->getId() << ","
                 << edge->getDistance() << "\n";
        }
    }
}

int MetroData::getMaxStationId(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return -1;
    }

    std::string line;
    int maxId = -1;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string token;
        // Ignore the first field in each line
        std::getline(iss, token, ',');
        while (std::getline(iss, token, ',')) {
            try {
                int id = std::stoi(token);
                if (id > maxId) {
                    maxId = id;
                }
            } catch (std::invalid_argument& e) {
                // Ignore invalid arguments
            }
        }
    }
    return maxId;
}


