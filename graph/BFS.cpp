#include<iostream>
#include<queue>
using namespace std;
void bfs(int **edges,int sv,int n)
{
    queue<int> q;
    q.push(sv);
    bool*visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    visited[sv]=true;
    while(!q.empty())
    {
        int front=q.front();
        cout<<front<<endl;
        q.pop();
        for(int i=0;i<n;i++)
        {
            if(i==front)
            {
                continue;
            }
            if(edges[front][i]==1 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    delete []visited;
}
/*
vertices 8
edges 9
0 4
0 5
4 3
3 2
2 1
1 3
5 6
3 6
6 7
 dfs
 0,4,3,1,2,6,5,7
 bfs
 0,4,5,3,6,1,2,7
 */
int main()
{
    int n;
    cout<<"enter no of vertices"<<endl;
    cin>>n;
    int e;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    cout<<"enter edges between"<<endl;
    for(int i=0;i<e;i++)
    {
        int f;
        int s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    bfs(edges,0,n);
    cout<<"abjacency matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }

}
