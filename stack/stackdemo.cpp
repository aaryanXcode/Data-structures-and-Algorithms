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
        nextIndex=0;
        capacity=totalSize;
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
    void display()
    {
        for(int i=nextIndex-1;i>=0;i--)
        {
            cout<<data[i]<<"\n";
        }
    }

};
int main()
{
    arrayStack A(4);
    int value;
    A.push(10);
	A.push(20);
	A.push(30);
	A.push(40);
    A.display();
    A.size();


}
