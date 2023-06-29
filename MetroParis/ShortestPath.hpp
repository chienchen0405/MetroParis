#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "MetroNetwork.hpp"
#include <vector>
#include <string>
#include <map>
#include <memory>

class ShortestPath {
public:
    // findShortestPath function now returns a pair of total distance and a vector of Node pointers along the path
    std::pair<double, std::vector<std::shared_ptr<Node>>> findShortestPath(const MetroNetwork& network, int sourceId, int destinationId);
};

#endif
