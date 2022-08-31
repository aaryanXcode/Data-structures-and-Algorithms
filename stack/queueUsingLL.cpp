#include<iostream>
using namespace std;
template<typename T>
class Node
{
    public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data=data;
        this->next=NULL;
    }
};
template<typename T>
class Queue
{
    public:
    T Size;
    Node<T> *head,*tail;
    Queue()
    {
        Size=0;
        head=NULL;
        tail=NULL;
    }
    void enqueue(T data)
    {
        Node<T> *newNode=new Node<T>(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;

        }
        else
        {
            tail->next=newNode;
            tail=tail->next;

        }
        Size++;
    }
    int getSize()
    {
        return Size;
    }
    bool isEmpty()
    {
        return Size==0;
    }
    T dequeue()
    {
        if(isEmpty())
        {
            return -1;
        }
        Node<T> *temp=head;
        T ans=temp->data;
        head=head->next;
        delete temp;
        Size--;
        return ans;
    }
    T front()
    {
        if(isEmpty())
        {
            return -1;
        }
        return head->data;
    }
};
int main()
{
    Queue<int> q;

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
	cout << q.dequeue() << endl;

	cout << q.front() << endl;
	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
}
