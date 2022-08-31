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
            capacity=4;
            nextIndex=0;
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
                return 0;
            }
            nextIndex--;
        }
        bool isEmpty()
        {
            return nextIndex==0;
        }
        int size()
        {
            return nextIndex;
        }
        T top()
        {
            if(isEmpty())
            {
                return 0;
            }
            return data[nextIndex-1];
        }
        void display()
        {
            if(isEmpty())
            {
                return;
            }
            for(int i=nextIndex-1;i>=0;i--)
            {
                cout<<data[i]<<endl;
            }
        }

};
int main()
{
    arrayStack<char> s;
    s.push(65);
    s.push(66);
    s.push(67);
    s.push(69);

    s.display();

    cout<<s.top()<<endl;

}
