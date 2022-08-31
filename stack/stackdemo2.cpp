#include<iostream>
using namespace std;
class arrayStack
{
    int *data;
    int capacity;
    int nextIndex;
public:
    arrayStack(int totalSize)
    {
        data=new int[totalSize];
        capacity=totalSize;
        nextIndex=0;

    }
    bool isEmpty()
    {
        return nextIndex==0;
    }
    int size()
    {
        return nextIndex;
    }
    void push(int value)
    {
        if(nextIndex==capacity)
        {
            cout<<"stack overflow\n";
        }
        data[nextIndex]=value;
        nextIndex++;
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"stack is empty\n";
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top()
    {
        if(isEmpty())
        {
            cout<<"stack is empty\n";
        }
        return data[nextIndex-1];
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"stack is empty\n";
        }
        for(int i=nextIndex-1;i>=0;i--)
        {
            cout<<data[i]<<endl;
        }
    }
};
int main()
{
    arrayStack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;

    s.display();
    s.pop();
    s.display();
}
