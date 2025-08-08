void bfs(vector<vector<int>>& adj, vector<int>& indegree, vector<int>& result, int V) {
    queue<int> q;
    
    // Push all nodes with indegree 0
    for(int i = 0; i < V; i++) {
        if(indegree[i] == 0) {
            q.push(i);  // FIXED: use node index, not indegree[i]
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        result.push_back(node);

        for (auto it : adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }
}

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for(auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }

    // Build indegree array
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    vector<int> topologicalOrder;
    bfs(adj, indegree, topologicalOrder, V); // FIXED: pass indegree and V

    // Optional: check for cycle
    if (topologicalOrder.size() != V) {
        // Cycle exists in graph
        return {}; // or throw an error
    }

    return topologicalOrder;
}
