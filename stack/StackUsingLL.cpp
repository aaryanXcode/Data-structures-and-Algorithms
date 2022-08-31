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
    ~Node()
    {
        delete next;
    }
};
template<typename T>
class Stack
{
    Node <T> *head,*tail;
    int Size;
public:
    Stack()
    {
        head=NULL;
        tail=NULL;
        Size=0;
    }
    void push(T element)
    {
        Node <T>*newNode=new Node<T>(element);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
            Size++;
        }
        else{
            tail->next=newNode;
            tail=tail->next;
            Size++;
        }
    }
    T Pop()
    {
        int count=0;
        Node <T> *temp;
        Node <T> *ptr=head;
        int item;
        temp=tail;
        item=temp->data;
        while(ptr->next!=NULL)
        {
            count++;
            cout<<count;
            ptr=ptr->next;

        }

        tail=ptr;
        delete temp;
        Size--;
        return item;
    }
    T top()
    {
        return tail->data;
    }
    int getSize()
    {
        return Size;
    }
    bool isEmpty()
    {
        return head==NULL;
    }
    void display()
    {
        while(head!=NULL)
        {
            cout<<head->data<<endl;
            head=head->next;
        }
    }
};
int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout<<"displaying all element\n";
    s.display();

    cout<<"popped:"<<s.Pop()<<endl;
    cout<<"Size"<<s.getSize()<<endl;

    cout<<"top element"<<s.top()<<endl;

    cout<<"popped:"<<s.Pop()<<endl;

    cout<<"Size"<<s.getSize()<<endl;

    cout<<"top element"<<s.top()<<endl;
}
