#include <bits/stdc++.h>
using namespace std;

void printEdgesArray(const vector<vector<int>>& edges, int n) {
    cout << "  ";
    for (int i = 0; i < n; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << i << ":";
        for (int j = 0; j < n; j++) {
            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(const vector<vector<int>>& edges, int n, int sv, vector<bool>& visited) {
    visited[sv] = true;
    cout << "sv: " << sv << endl;
    for (int i = 0; i < n; i++) {
        if (i == sv) continue;
        if (edges[sv][i] == 1 && !visited[i])
            dfs(edges, n, i, visited);
    }
}

void bfs(const vector<vector<int>>& edges, int n, int sv, vector<bool>& visited) {
    queue<int> q;
    q.push(sv);
    visited[sv] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Visited: " << current << endl;

        for (int i = 0; i < n; i++) {
            if (i == current) continue;
            if (edges[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void dfsDisconnect(const vector<vector<int>>& edges, int n) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(edges, n, i, visited);
        }
    }
}

void bfsDisconnect(const vector<vector<int>>& edges, int n) {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(edges, n, i, visited);
        }
    }
}

bool hasPath(const vector<vector<int>>& edges, int n, int sv, vector<bool>& visited, int ev) {
    visited[sv] = true;
    if (sv == ev) return true;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && edges[sv][i] == 1) {
            if (hasPath(edges, n, i, visited, ev))
                return true;
        }
    }
    return false;
}

vector<int> getPath(vector<vector<int>>& edges, int n, int sv, vector<bool>& visited, int ev) {
    if (sv == ev) {
        return {sv};  // base case: destination found
    }

    visited[sv] = true;

    for (int i = 0; i < n; i++) {
        if (edges[sv][i] == 1 && !visited[i]) {
            vector<int> smallOutput = getPath(edges, n, i, visited, ev);
            if (!smallOutput.empty()) {
                smallOutput.push_back(sv);  // backtrack
                return smallOutput;
            }
        }
    }
    return {};  // no path found
} 

int main() {
    int n, e;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    vector<vector<int>> edges(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++) {
        int f, s;
        cout << "Enter edge between vertices: ";
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    printEdgesArray(edges, n);

    vector<bool> visited(n, false);
    cout << "DFS traversal:\n";
    dfs(edges, n, 0, visited);

    visited.assign(n, false);
    cout << "\nBFS traversal:\n";
    bfs(edges, n, 0, visited);

    cout << "\nDisconnected DFS:\n";
    dfsDisconnect(edges, n);

    cout << "\nDisconnected BFS:\n";
    bfsDisconnect(edges, n);

    // int sv, ev;
    // cout << "\nEnter source and destination to check path: ";
    // cin >> sv >> ev;
    // visited.assign(n, false);
    // if (hasPath(edges, n, sv, visited, ev)) {
    //     cout << "Path exists.\n";
    // } else {
    //     cout << "No path exists.\n";
    // }

    visited.assign(n,false);
    int sv,ev;
    cout << "\nEnter source and destination to get path: ";
    cin >> sv >> ev; 
    vector<int> getpath = getPath(edges,n,sv,visited,ev);

    cout<<"path: \n";
    for(auto path:getpath){
        cout<<path<<" ";
    }
    cout<<endl;
    return 0;
}
