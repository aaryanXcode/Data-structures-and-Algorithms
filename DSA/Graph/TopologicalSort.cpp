#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& adj, vector<bool>& visited, stack<int>& top, int sv){
    visited[sv] = true;
    for(auto neighbor: adj[sv]){
        if(!visited[neighbor]){
            dfs(adj, visited, top, neighbor);
        }
    }
    top.push(sv);
}
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    // code here
    //it will be a directed graph 
    vector<vector<int>> adj(V);
    for( auto &edge: edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    
    vector<bool> visited(V,false);
    stack<int> topologicalOrder;
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(adj, visited, topologicalOrder, i);
        }
    }
    for(int i = 0; i < V; i++){
        if(!visited[i]){
            topologicalOrder.push(i);
        }
    }
    vector<int> ans;
    while(!topologicalOrder.empty()){
        ans.push_back(topologicalOrder.top());
        topologicalOrder.pop();
    }
    return ans;
}