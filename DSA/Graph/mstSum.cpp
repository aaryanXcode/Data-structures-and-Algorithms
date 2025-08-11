typedef pair<int,int> P;
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
    vector<vector<P>> adj(V);
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2];
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    vector<bool> visited(V,false);
    priority_queue<P, vector<P>, greater<P>> pq;
    
    pq.push({0,0});
    int sum = 0;
    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int w = p.first;
        int node = p.second;
        
        if(visited[node]) continue;
        
        visited[node] = true; //added to mst
        sum +=w;
        
        for (auto &[neigh_wt, neigh] : adj[node]) {
            if (!visited[neigh]) {
                pq.push({neigh_wt, neigh});
            }
        }
        
    }
    return sum;
    
}