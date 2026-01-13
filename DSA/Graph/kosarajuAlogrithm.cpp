#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj, int source, vector<bool>& visited, stack<int>& st){
    visited[source] = true;
    for(auto neigh: adj[source]){
        if(!visited[neigh]){
            dfs(adj, neigh, visited, st);
        }
    }
    st.push(source);
}
void dfs2(vector<vector<int>> &adj, int source, vector<bool>& visited){
    visited[source] = true;
    for(auto neigh: adj[source]){
        if(!visited[neigh]){
            dfs2(adj, neigh, visited);
        }
    }
}
int kosaraju(vector<vector<int>> &adj) {
    // code here
    int v = adj.size();
    vector<vector<int>> transpose(v);

    
    stack<int> st;
    vector<bool> visited(v, false);
    for(int i = 0; i<v; i++){
        if(!visited[i]){
            dfs(adj, i, visited, st);
        }
    }
    fill(visited.begin(), visited.end(), false);
    for(int u = 0; u < v; u++){
        for(int vtx : adj[u]){
            transpose[vtx].push_back(u);
        }
    }
    
    int count = 0;
    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!visited[top]){  
            dfs2(transpose, top, visited);
            count++;
        }
    }
    return count;
    
}
