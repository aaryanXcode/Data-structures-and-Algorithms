#include<iostream>
using namespace std;
template <typename T>
class Queue
{
    T *data;
    int nextIndex;
    int firstIndex;
    int Size;
    int capacity;
    public:
    Queue(T totalSize)
    {
        data=new T[totalSize];
        Size=0;
        nextIndex=0;
        firstIndex=-1;
        capacity=totalSize;
    }
    int getSize()
    {
        return Size;
    }
    bool isEmpty()
    {
        return Size==0;
    }
    void enqueue(T val)
    {
        if(capacity==Size)
        {
            cout<<"queue is full"<<endl;
            return;
        }
        data[nextIndex]=val;
        nextIndex=(nextIndex+1)%capacity;
        if(firstIndex==-1)
        {
            firstIndex=0;
        }
        Size++;
    }
    T front()
    {
        if(isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        Size--;
        if(Size==0)
        {
            firstIndex=-1;
            nextIndex=0;
        }
        return ans;

    }



};
int main()
{
    Queue<int> q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);


	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;

}
