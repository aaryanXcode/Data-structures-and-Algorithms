#include<iostream>
using namespace std;
class MinStack {
    int *data;
    int capacity;
    int nextIndex;
public:
    MinStack() {
        data=new int[4];
        nextIndex=0;
        capacity=4;
    }
    bool isEmpty()
    {
        return nextIndex==0;
    }

    void push(int val) {
        if(nextIndex==capacity)
        {
            int *newdata=new int[capacity*2];
            for(int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];
            }
            capacity=capacity*2;
            delete data;
            newdata=data;
        }
        data[nextIndex]=val;
        nextIndex++;

    }

    void pop() {
       if(isEmpty())
       {
           return;
       }
        nextIndex--;

    }

    int top() {
        if(isEmpty())
        {
            return -1;
        }
        return data[nextIndex-1];
    }

    int getMin() {
        int min=data[nextIndex-1];
        for(int i=nextIndex-1;i>=0;i--)
        {
            if(min>data[i])
            {
                min=data[i];
            }
        }
        return min;
    }
};
int main()
{
    MinStack s;
    s.push(NULL);
    s.push(-10);
    cout<<s.getMin()<<endl;
    cout<<s.getMin()<<endl;
    s.push(14);
    cout<<s.getMin()<<endl;
    cout<<s.getMin()<<endl;
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    s.pop();
    s.push(NULL);
    s.push(NULL);
    cout<<s.getMin()<<endl;
    s.push(-20);
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
    s.pop();
    s.push(NULL);
    s.push(NULL);
    s.push(NULL);
    s.push(NULL);
    s.push(NULL);
    s.push(10);
    s.push(-7);
    s.push(NULL);
    s.push(-7);
    s.getMin();
    s.push(NULL);
    s.push(NULL);
    s.push(NULL);
    s.push(NULL);



}
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 class MinStack {
    int *data;
    int *min;
    int capacity;
    int index;
    int nextIndex;
    int size;
public:
    MinStack() {
        data=new int[4];
        min=new int[4];
        nextIndex=0;
        capacity=4;
        size=4;
    }
    bool isEmpty()
    {
        return nextIndex==0;
    }

    void push(int val) {
        if(nextIndex==capacity)
        {
            int *newdata=new int[capacity*2];
            for(int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];
            }
            capacity=capacity*2;
            delete data;
            data=newdata;;
        }
        if(index==capacity)
        {
            int size=capacity;
            int *nedata=new int[size*2];
            for(int i=0;i<size;i++)
            {
                nedata[i]=min[i];
            }
            size=size*2;
            delete min;
            min=nedata;
        }
        if(isEmpty() || val<=min[index-1])
        {
            min[index]=val;
            index++;
        }

        data[nextIndex]=val;
        nextIndex++;

    }

    void pop() {
       if(isEmpty())
       {
           return;
       }
       nextIndex--;
       if(data[nextIndex-1]==min[index-1])
            index--;

    }

    int top() {
        if(isEmpty())
        {
            return -1;
        }
        return data[nextIndex-1];
    }

    int getMin() {
        if(isEmpty())
        {
            return -1;
        }
        else
            return min[index-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

