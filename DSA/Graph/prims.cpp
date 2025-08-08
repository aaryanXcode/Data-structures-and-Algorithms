//Algorithm
//

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, e;
    cout<<"enter vertex and edges:"<<endl;
    cin>>n>>e;

    vector<vector<pair<int,int>>> adj(n);

    //step 1:
    //adjancy list has been prepared : graph but it should be with some weight
    for(int i =0;i<e;i++){
        int s,d,w;
        cout<<"enter edge between source and destination and weight:";
        cin>>s>>d>>w;
        adj[s].push_back({d,w});
        adj[d].push_back({s,w});
    }

    //step2 : 
    vector<int> parent(n,-1);
    vector<int> weight(n,INT_MAX);
    vector<bool> visited(n,false);
    

    //let start with 0 so
    weight[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        // Step 3: Pick the minimum weight unvisited vertex 
        int minVertex = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])) {
                minVertex = i;
            }
        }
        //found the minimum vertex which has not visited  marked it true

        visited[minVertex] = true;

        //now traverse the neighbour of visited vertex
        for(auto neighbor:adj[minVertex]){
            int v = neighbor.first;
            int w = neighbor.second;
            if (!visited[v] && w < weight[v]) {
                weight[v] = w;
                parent[v] = minVertex;
            }
        }
        
    }
    
    cout << "Minimum Spanning Tree edges:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " with weight " << weight[i] << endl;
    }

}

// 0->{1,4},{2,8};
// 1->{0,4},{2,2},{3,6}
// 2->{0,8},{1,2},{3,3},{4,9}
// 3->{1,6},{2,3},{4,5}

//dry run
/*
| Step | Visited   | Picked Vertex | Updated Vertex | Parent | Weight |
| ---- | --------- | ------------- | -------------- | ------ | ------ |
| 0    | —         | Start at 0    | 0              | -1     | 0      |
| 1    | {0}       | 1 (min=4)     | 1              | 0      | 4      |
|      |           |               | 2              | 1      | 2      |
|      |           |               | 3              | 1      | 6      |
| 2    | {0,1}     | 2 (min=2)     | 2              | 1      | 2      |
|      |           |               | 3              | 2      | 3      |
|      |           |               | 4              | 2      | 9      |
| 3    | {0,1,2}   | 3 (min=3)     | 3              | 2      | 3      |
|      |           |               | 4              | 3      | 5      |
| 4    | {0,1,2,3} | 4 (min=5)     | 4              | 3      | 5      |
*/
