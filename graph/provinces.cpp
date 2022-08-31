#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void printDFS(int **isConnected,int sv,int n,bool *visited)
{
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(i==sv)
        {
            continue;
        }
        if(isConnected[sv][i]==1)
        {
            if(visited[i])
            {
                continue;
            }
        }
        printDFS(isConnected,i,n,visited);
    }
}
int DFS(int ** isConnected,int n)
{
    int count=0;
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            printDFS(isConnected,i, n,visited);
            count++;
        }
    }
    return count;
}
int findCircleNum(int ** isConnected,int n)
{

    return DFS(isConnected,n);
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



    cout<<"abjacency matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<edges[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<findCircleNum(edges,n);
}

