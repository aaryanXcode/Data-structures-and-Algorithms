#include<bits/stdc++.h>
using namespace std;

void printAdjacancyMatrix(int** edges, int n){
    cout<<"  ";
    for(int i =0;i<n;i++){
        cout<<i<<" ";
    }
    cout<<endl;
    for(int i =0; i<n;i++){
        cout<<i<<":";
        for(int j = 0;j<n;j++){
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void dfs(int** edges,int n,int sv,bool* visited){
    visited[sv] = true;
    cout<<"current vertex:"<<sv<<endl;
    for(int i =0;i<n;i++){
        if(edges[i][sv]==1 && !visited[i]){
            dfs(edges,n,i,visited);
        }
    }
}

void bfs(int** edges,int n,int sv,bool* visited){
    queue<int> pendingEdges;
    pendingEdges.push(sv);
    visited[sv] = true;
    while(!pendingEdges.empty()){
        int currentVertex = pendingEdges.front();
        pendingEdges.pop();
        cout<<"current vertex:"<<currentVertex<<endl;
        for(int i =0;i<n;i++){
            if(edges[currentVertex][i]==1 && !visited[i]){
                pendingEdges.push(i);
                visited[i] = true;
            }
        }
    }
}
int main(){
    int n,e;
    cout<<"enter vertexes and their edges:";
    cin>>n>>e;

    //will create adjacenecy matrix
    int** edges = new int*[n];

    for(int i =0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] =0;
        }
    }


    //connect vertex with edges
    for(int i =0;i<e;i++){
        
        int f,s;
        cout<<"enter edge between vertices"<<endl;
        cin>>f>>s;
        edges[f][s] =1;
        edges[s][f] =1;
        
    }

    printAdjacancyMatrix(edges,n);

    bool* dfsvisited = new bool[n];
    bool* bfsvisited = new bool[n];
    for(int i =0;i<n;i++){
        dfsvisited[i]=false;
        bfsvisited[i]=false;
    }
    cout<<"\n dfs traversal: \n";
    dfs(edges,n,0,dfsvisited);

    cout<<"\n bfs traversal: \n";
    bfs(edges,n,0,bfsvisited);

}