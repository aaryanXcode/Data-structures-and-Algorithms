//graph implementation adjacency matrix
#include<iostream>
using namespace std;
void print(int **edges,int n,int sv,bool *visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        {
            continue;
        }
        if(edges[sv][i]==1)
        {
            if(visited[i])
            {
                continue;
            }
            print(edges,n,i,visited);
        }
    }
}

/*
inout
5 6   vertices and edges
0 1
1 2
2 3
3 4
4 0
4 1
adjaency mat
0 1 0 0 1
1 0 1 0 1
0 1 0 1 0
0 0 1 0 1
1 1 0 1 0
//dfs
0
1
2
3
4
*/

int main()
{
    int n;
    int e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    //connecting edges
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }


    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

    print(edges,n,0,visited);

    //delete
    for(int i=0;i<n;i++)
    {
        delete[] edges[i];
    }
    delete [] edges;
}
