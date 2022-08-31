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
Node *AppendLastNToFirst(Node *head,int pos)
{
    int count=0;
    Node* current;
    Node *previous;
    Node* lastNode=NULL;
    Node *ptr=head;
    while(ptr!=NULL)
    {
        count++;
        cout<<ptr->data;
        ptr=ptr->next;
    }
    pos=count-pos;
    cout<<"pos:"<<pos<<"\n";

    lastNode=ptr-1;
    cout<<ptr->data;

    lastNode->next=head;
    while(pos!=1)
    {
        previous=current;
        current=current->next;
        pos--;
    }
    previous->next=NULL;
    lastNode->next=head;
    return lastNode;

}
int main()
{
    int pos;
    Node *head=createNode();
    print(head);
    cout<<"enter position from where you want to rotate\n";
    cin>>pos;
    AppendLastNToFirst(head,pos);
    print(head);
}
