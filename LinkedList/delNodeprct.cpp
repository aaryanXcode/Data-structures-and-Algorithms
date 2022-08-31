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
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL\n";
}
void deleteNode(Node *head,int pos)N
{
    Node *current=head;
    Node *previous=head;
    if(head==NULL)
    {
        cout<<"list is empty\n";
    }
    else if(pos==1)
    {
        head=current->next;
        delete current;
        current=NULL;
    }
    else
    {
        while(pos!=1)
        {
            previous=current;
            current=current->next;
            pos--;
        }
        previous->next=current->next;
        delete current;
        current=NULL;
    }
}
int main()
{
    int pos;
    Node *head=createNode();
    print(head);
    cout<<"enter position to be delete\n";
    cin>>pos;
    deleteNode(head,pos);
    print(head);

}
