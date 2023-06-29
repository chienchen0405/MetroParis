#include "ShortestPath.hpp"
#include <queue>
#include <climits>

std::pair<double, std::vector<std::shared_ptr<Node>>> ShortestPath::findShortestPath(const MetroNetwork& network, int sourceId, int destinationId) {
    const std::map<int, std::shared_ptr<Node>>& nodes = network.getNodes();

    if(nodes.find(sourceId) == nodes.end() || nodes.find(destinationId) == nodes.end()) {
        throw std::invalid_argument("Source or destination node not found in the network.");
    }

    std::map<int, double> dist;
    std::map<int, int> prev;

    for (const auto& pair : nodes) {
        dist[pair.first] = INT_MAX;
        prev[pair.first] = -1;
    }

    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;

    dist.at(sourceId) = 0;
    pq.push(std::make_pair(0, sourceId));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (dist.at(u) == INT_MAX) {
            continue;
        }

        for (const auto& edge : network.getEdgesFromStation(u)) {
            int v = edge->getDestination()->getId();
            double weight = edge->getDistance();

            double newDist = dist.at(u) + weight;

            if (newDist < dist.at(v)) {
                dist.at(v) = newDist;
                prev.at(v) = u;
                pq.push(std::make_pair(dist.at(v), v));
            }
        }
    }

    std::vector<std::shared_ptr<Node>> path;
    int current = destinationId;
    while (current != -1) {
        path.push_back(nodes.at(current));
        current = prev.at(current);
    }

    std::reverse(path.begin(), path.end());

    return std::make_pair(dist.at(destinationId), path);
}
