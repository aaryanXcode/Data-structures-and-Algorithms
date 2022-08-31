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
    Node *temp=NULL;
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
            tail->next=head;
            temp=tail->next;
            tail->next=newNode;
            newNode->next=temp;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{
    Node *ptr=head;
    do
    {
        cout<<ptr->data<<"->";
        ptr=ptr->next;
    }
    while(ptr!=head);
    cout<<"cycle\n";
}
Node *findx(Node *head)
{
    Node *slow=head;
    Node *fast=head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        {
            return slow;
        }
    }


}
void mid(Node *head)
{

    Node *slow=head;
    Node *fast=head;
    while(fast->next!=head && fast->next->next!=head)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}
//insertion a last position
Node *insertAtLast(Node *head)
{
    int data;
    Node *ptr=head;
    cout<<"enter value want to insert\n";
    cin>>data;
    Node *newNode=new Node(data);
    while(ptr -> next != head)
    {
        ptr = ptr -> next;
    }
    ptr -> next = newNode;
    newNode -> next = head;
    return head;

}
int main()
{
    Node *head=createNode();
    print(head);
    findx(head);
    Node *nwNd=findx(head);
    print(nwNd);
    mid(head);
    Node *modifiedNode=insertAtLast(head);
    print(modifiedNode);

}
