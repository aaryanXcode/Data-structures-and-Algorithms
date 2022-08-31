#include<iostream>
using namespace std;
template<typename T>
class arrayStack
{

    T *data;
    int nextIndex;
    int capacity;
    public:
    arrayStack()
    {
        data=new T[4];
        nextIndex=0;
        capacity=4;
    }
    void push(int val)
    {
        if(nextIndex==capacity)
        {
            T *newdata=new T[4];
            for(int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];
            }
            capacity*=2;
            delete data;
            data=newdata;
        }
        data[nextIndex]=val;
        nextIndex++;
    }
    T pop()
    {
        if(isEmpty())
        {
            cout<<"underflow"<<endl;
        }
        nextIndex--;
        return data[nextIndex];
    }
    T top()
    {
        if(isEmpty())
        {
            cout<<"underflow"<<endl;
        }
        return data[nextIndex-1];
    }
    bool isEmpty()
    {
        return nextIndex==0;
    }
};
int main()
{
    arrayStack <int> s;
    s.push(65);
    s.push(66);
    s.push(67);
    s.push(69);



    cout<<s.top()<<endl;
}
