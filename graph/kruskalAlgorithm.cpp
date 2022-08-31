#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Edge
{
    public:
    int source;
    int destination;
    int weight;
};
bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}
int findParent(int v,int *parent)
{
    if(parent[v]==v)
    {
        return v;
    }
    return findParent(parent[v],parent);
}
void kruskal(Edge *input,int n,int E)
{
    cout<<"before sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<input[i].source<<" "<<input[i].destination<<" "<<input[i].weight<<endl;
    }
    sort(input,input+E,compare) ;  //sort according to weight
    cout<<"after sort"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<input[i].source<<" "<<input[i].destination<<" "<<input[i].weight<<endl;
    }
    Edge *output=new Edge[n];
    int *parent=new int[n];      //creating parent array
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
    int count=0;
    int i=0;
    while(count!=n-1)
    {
        Edge currentEdge=input[i];
        int sourceParent=findParent(currentEdge.source,parent);
        int destParent=findParent(currentEdge.destination,parent);
        if(sourceParent!=destParent)
        {
            output[count]=currentEdge;
            count++;
        }
        i++;
    }

    for(int i=0;i<n-1;i++)
    {

       cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        /*if(output[i].source<output[i].destination)
        {
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        }
        else
        {
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
        */
    }
}

int main()
{
    int n,E;
    cin>>n>>E;   //n= vertices ,E=edges
    Edge *input=new Edge[n];
    for(int i=0;i<E;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].destination=d;
        input[i].weight=d;
    }
    kruskal(input,n,E);
}
