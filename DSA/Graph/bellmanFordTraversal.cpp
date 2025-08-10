//dijkistra fails to compute when edge has negative weights it can be trapped in negative weight cycle,
//bellman helps to overcome thhis situation

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
    vector<int> distance(V,1e8);
    distance[src] = 0;
    for(int i =0; i<V; i++){
        for(auto edge :edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(distance[u]!=1e8 && distance[u]+wt < distance[v]){
                
                distance[v] = distance[u]+ wt;
            }
        }
    }
    
    for(auto edge :edges){
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        if(distance[u]!=1e8 && distance[u]+wt < distance[v]){
            
            return {-1};
        }
    }
        
    return distance;
    
}