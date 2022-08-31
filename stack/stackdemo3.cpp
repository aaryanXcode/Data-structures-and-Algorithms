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
        data =new int[totalSize];
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
    int pop()
    {
        if(isEmpty())
        {
            cout<<"stack is empty\n";
        }
        nextIndex--;
        return data[nextIndex];

    }
    int push(int value)
    {
        if(capacity==nextIndex)
        {
            cout<<"stack is empty\n";
        }
        data[nextIndex]=value;
        nextIndex++;
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
    int top()
    {
        if(isEmpty())
        {
            cout<<"stack is empty\n";
        }
        return data[nextIndex-1];
    }
};
int main()
{
    arrayStack s(4);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<s.top()<<endl;
    s.display();
}
