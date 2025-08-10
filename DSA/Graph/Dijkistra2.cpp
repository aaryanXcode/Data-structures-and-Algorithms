//using priority quese and adjcancy matrix

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<int> dijkstra(int src, const vector<vector<pair<int,int>>>& graph) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[src] = 0;

    // Min-heap priority queue: pairs of (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [currDist, u] = pq.top();
        pq.pop();

        // Ignore outdated pairs
        if (currDist > dist[u]) continue;

        for (auto& [v, weight] : graph[u]) {
            int newDist = dist[u] + weight;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int,int>>> graph(n);

    // Build the graph: graph[u].push_back({v, weight});
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({4, 3});
    graph[3].push_back({4, 1});

    int src = 0;
    vector<int> dist = dijkstra(src, graph);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < n; ++i) {
        if (dist[i] == numeric_limits<int>::max()) 
            cout << "Node " << i << ": unreachable\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}
