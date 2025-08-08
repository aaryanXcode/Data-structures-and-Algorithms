bool isCycleDFS(vector<vector<int>>& adj, vector<bool>& visited, int parent, int u){
    visited[u] = true;
    
    for(auto neighbor : adj[u]){
        if(neighbor==parent) continue;
        if (visited[neighbor]) {
            return true;
        }

        if (isCycleDFS(adj, visited, u, neighbor)) {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<vector<int>>& edges) {
    // Code here
    vector<vector<int>> adj(V);
    for( auto &edge: edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<bool> visited(V,false);
    vector<int> parent(V,-1);
    for(int i = 0; i<V; i++){
        if(!visited[i] && isCycleDFS(adj, visited, -1, i))
        {
            return true;
        }
    }
    
    return false;
}