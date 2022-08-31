#include<iostream>
#include<queue>
using namespace std;

void printDFS(int **edges,int n,int sv,bool *visited)
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
            printDFS(edges,n,i,visited);
        }
    }
}

void printBFS(int **edges,int sv,int n,bool*visited)
{
    queue<int> q;
    q.push(sv);
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

}
void BFS(int **edges,int n)
{
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
             printBFS(edges,i,n,visited);
        }

    }
    delete [] visited;
}
void DFS(int **edges,int n)
{
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
             printDFS(edges,n,i,visited);
        }
    }

    delete [] visited;

}
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

    cout<<"BFS"<<endl;
    BFS(edges,n);
    cout<<"DFS"<<endl;
    DFS(edges,n);
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

