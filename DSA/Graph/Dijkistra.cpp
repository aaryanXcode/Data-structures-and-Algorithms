#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,e;
    cout<<"Enter number of vertex and edges:"<<endl;
    cin>>n>>e;
    vector<vector<pair<int,int>>> adj(n);
    for(int i =0;i<e;i++){
        int s,d,w;
        cout<<"enter source, destination, and weight:"<<endl;
        cin>>s>>d>>w;
        adj[s].push_back({d,w});
        adj[d].push_back({s,w});
    }

    vector<int> distance(n,INT_MAX);
    vector<bool> visited(n,false);
    distance[0] = 0;
    

    for(int i = 0;i<n;i++){
        int minVertex = -1;
        //find vertex with minimum weight
        for(int j = 0;j<n;j++){
            if(!visited[j] && (minVertex==-1 || distance[j]<distance[minVertex])){
                minVertex = j;
            }
        }

        visited[minVertex] = true;

        //explore the neighbor of min vertex
        for(auto neighbor : adj[minVertex]){
            int v = neighbor.first;
            int w = neighbor.second;
            if (!visited[v] && distance[minVertex] + w < distance[v]) {
                distance[v] = distance[minVertex] + w;
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from source node 0:" << endl;
    for (int i = 0; i < n; i++) {
        if (distance[i] == INT_MAX)
            cout << "Node " << i << ": Unreachable" << endl;
        else
            cout << "Node " << i << ": " << distance[i] << endl;
    }

    return 0;
}