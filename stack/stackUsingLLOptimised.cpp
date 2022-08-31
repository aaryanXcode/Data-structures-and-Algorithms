#include<iostream>
using namespace std;
template<typename T>
class Node
{
    public:
    T data;
    Node *next;
    Node(T element)
    {
        this->data=element;
        this->next=NULL;
    }
};
template <typename T>
class Stack
{

    int Size;
    Node <T> *head,*tail;
public:
    Stack()
    {
        head=NULL;
        tail=NULL;
    }
    void push(T element)
    {
        Node <T> *newNode=new Node<T>(element);
        newNode->next=head;
        head=newNode;
        Size++;
    }
    T top()
    {
        T item =head->data;
        return item;
    }
    T pop()
    {
        T ans=head->data;
        Node<T> *temp=head;
        head=head->next;
        delete temp;
        Size--;
        return ans;
    }
    int getSize()
    {
        return Size;
    }
    bool isEmpty()
    {
        return Size==0;
    }

};
int main()
{
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);



    cout<<"top element:"<<s.top()<<endl;


    s.push(5);
    cout<<"top element:"<<s.top()<<endl;

    cout<<"pop:"<<s.pop()<<endl;

    cout<<"top element:"<<s.top()<<endl;
    cout<<"pop:"<<s.pop()<<endl;
    cout<<"top element:"<<s.top()<<endl;




}
