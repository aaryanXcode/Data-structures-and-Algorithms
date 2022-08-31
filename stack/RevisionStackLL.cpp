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
class Stack
{
    int Size;
    Node <T> *head;
public:
    Stack()
    {
        head=NULL;

        Size=0;
    }
    void push(T val)
    {
        Node <T> *newNode=new Node<T>(val);
        newNode->next=head;
        head=newNode;
        Size++;
    }
    T pop()
    {
        T ans=head->data;
        Node<T> *temp=head;
        head=head->next;
        delete temp;
        return ans;
        Size--;
    }
    bool isEmpty()
    {
        return Size==0;
    }
    int getSize()
    {
        return Size;
    }
    T top()
    {
        return head->data;
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
