bool isCycleDFS(vector<vector<int>>& adj, vector<bool>& visited, int u){
        queue<pair<int,int>> q;
        q.push({u,-1});
        visited[u] = true;
        while(!q.empty()){
            auto [u,parent] = q.front();
            q.pop();
            
            for(auto neighbour: adj[u]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push({neighbour,u});
                }
                else if(neighbour != parent){
                    return true;
                }
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
            if(!visited[i] && isCycleDFS(adj, visited, i))
            {
                return true;
            }
        }
        
        return false;
    } 