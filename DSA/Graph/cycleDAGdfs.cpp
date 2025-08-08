bool dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &inStack, int source) {
    visited[source] = true;
    inStack[source] = true;
    
    for (auto neighbour : adj[source]) {
        if (!visited[neighbour]) {
            if (dfs(adj, visited, inStack, neighbour)) {
                return true;
            }
        } else if (inStack[neighbour]) {
            return true;
        }
    }

    inStack[source] = false; // backtrack
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v); // directed edge
    }

    vector<bool> visited(V, false);
    vector<bool> inStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(adj, visited, inStack, i)) {
                return true; // cycle found
            }
        }
    }

    return false; // no cycle
}
