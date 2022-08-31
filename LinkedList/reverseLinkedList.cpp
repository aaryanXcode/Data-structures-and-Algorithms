#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
Node *createNode()
{
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=-1)
    {
        Node *newNode=new Node(data);
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
        cin>>data;
    }
    return head;

}
Node *reverselinkedList(Node *head)
{
    Node *prev=NULL;
    Node *next=NULL;
    while(head!=NULL)
    {
        next=head->next;
        head->next=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL\n";
}
int main()
{
    Node *head=createNode();
    print(head);
    Node *newhead=reverselinkedList(head);
    print(newhead);
}
