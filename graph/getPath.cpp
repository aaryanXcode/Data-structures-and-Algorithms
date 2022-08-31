#include<iostream>
using namespace std;
int main()
{
    int vertices;
    int edges;
    cin>>vertices>>edges;
    int **graph=new int*[vertices];
    for(int i=0;i<vertices;i++)
    {
        graph[i]=new int[vertices];
        for(int j=0;j<vertices;j++)
        {
            graph[i][j]=0;
        }
    }

    for(int i=0;i<edges;i++)
    {
        int f;
        int s;
        cin>>f>>s;
        graph[f][s]=1;
        graph[s][f]=1;
    }

    bool *visited=new bool[vertices];
    for(int i=0;i<vertices;i++)
    {
        visited[i]=false;
    }

    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<vertices;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<vertices;i++)
    {
        delete [] graph[i];
    }
    delete []graph;
}

