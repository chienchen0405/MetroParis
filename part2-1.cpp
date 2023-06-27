#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
private:
    vector<vector<pair<int, int> > > nodes;

public:
    void addNode(int val) {
        nodes.push_back(vector<pair<int, int> >());
    }

    void addEdge(int src, int dest, int weight) {
        nodes[src].push_back(make_pair(dest, weight));
        nodes[dest].push_back(make_pair(src, weight));
    }

    pair<int, vector<int> > shortestPath(int start, int end) {
        int n = nodes.size();

        vector<int> dist(n, INT_MAX);
        vector<int> prev(n, -1);

        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

        dist[start] = 0;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (dist[u] == INT_MAX) {
                continue;
            }

            for (vector<pair<int, int> >::iterator it = nodes[u].begin(); it != nodes[u].end(); ++it) {
                int v = it->first;
                int weight = it->second;

                int newDist = dist[u] + weight;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    prev[v] = u;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        vector<int> path;
        int current = end;
        while (current != -1) {
            path.push_back(current);
            current = prev[current];
        }
        reverse(path.begin(), path.end());

        return make_pair(dist[end], path);
    }
};

int main() {
    Graph graph;

    graph.addNode(0);
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 2);

    pair<int, vector<int> > shortestPath = graph.shortestPath(0, 4);

    cout << "Shortest Path Length: " << shortestPath.first << endl;
    cout << "Shortest Path: ";
    for (vector<int>::iterator it = shortestPath.second.begin(); it != shortestPath.second.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
