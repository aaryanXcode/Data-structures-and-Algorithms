#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> p;
    p.push(19);   //push is used for inserting element in heap
    p.push(20);
    p.push(100);
    p.push(48);
    p.push(43);
    p.push(0);

    cout<<"size "<<p.size()<<endl;
    cout<<"max heap:"<<p.top()<<endl;

    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
}
