#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int source;
    int destination;
    int weight;
};

// Comparator for sorting edges by weight
bool comparator(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

// Union-Find: Find with no path compression (simple version)
int findParent(int v, int* parent) {
    if (parent[v] == v) {
        return v;
    }
    return findParent(parent[v], parent);
}

// Kruskal's Algorithm
void kruskal(Edge* edge, int n, int e) {
    sort(edge, edge + e, comparator);

    Edge* output = new Edge[n - 1]; // MST will have n-1 edges
    int* parent = new int[n];

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while (count < n - 1 && i < e) {
        Edge currentEdge = edge[i];

        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.destination, parent);

        if (sourceParent != destParent) {
            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent; // union
        }
        i++;
    }

    // Output MST edges
    for (int i = 0; i < count; i++) {
        cout << "source: " << output[i].source
             << " destination: " << output[i].destination
             << " weight: " << output[i].weight << endl;
    }

    delete[] output;
    delete[] parent;
}

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    Edge* edge = new Edge[e];

    cout << "Enter edges (source destination weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> edge[i].source >> edge[i].destination >> edge[i].weight;
    }

    kruskal(edge, n, e);

    delete[] edge;
}
