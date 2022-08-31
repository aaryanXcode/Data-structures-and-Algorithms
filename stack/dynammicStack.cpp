#include<iostream>
using namespace std;
class arrayStack
{
    int *data;
    int capacity;
    int nextIndex;
    public:
    arrayStack()
    {
        data=new int[4];
        nextIndex=0;
        capacity=4;
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
    int top()
    {
        if(isEmpty())
        {
            cout<<"stack is empty\n";
        }
        return data[nextIndex-1];
    }
    int push(int value)
    {
        if(nextIndex==capacity)
        {
            int *newData=new int[capacity*2];
            for(int i=0;i<capacity;i++)
            {
                newData[i]=data[i];
            }
            capacity=capacity*2;
            delete data;
            data=newData;
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
};
int main()
{
    arrayStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s.display();
    s.pop();
    cout<<"after pop\n";
    s.display();

    cout<<"stack top\n";
    cout<<s.top()<<endl;
}


/*dynammic stack
int *newdata=new int[capacity*2];
for(int i=0;i<capacity;i++)
{
    newdata[i]=data[i];
}
delete data;
data=newdata;
capacity=capacity*2;
*/
