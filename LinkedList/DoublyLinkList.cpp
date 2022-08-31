#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *prev;
    Node * next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
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
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{
    cout<<"NULL<->";
    while(head!=NULL)
    {
        cout<<head->data<<"<->";
        head=head->next;
    }
    cout<<"NULL\n";
}
void *insertAtLast(Node *head)
{
    int data;
    cout<<"enter value you want to insert\n";
    cin>>data;
    Node *newNode=new Node(data);
    Node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newNode;
    newNode->prev=ptr;
    newNode->next=NULL;
}
Node *insertAtBeg(Node *head)
{
    int data;
    cout<<"enter value you want to insert\n";
    cin>>data;
    Node *newNode=new Node(data);
    newNode->prev=NULL;
    head->prev=newNode;
    newNode->next=head;
    return newNode;
}
void inserAtSpecific(Node *head,int pos)
{
    int data;
    cout<<"enter value u want to insert\n";
    cin>>data;
    Node *newNode=new Node(data);
    Node *ptr=head;
    Node *temp=NULL;
    while(pos)
    {
        ptr=ptr->next;
        pos--;
    }
    temp=ptr->next;
    ptr->next=newNode;
    newNode->prev=ptr;
    newNode->next=temp;
}
void delAtSpecific(Node *head,int pos)
{
    Node *ptr=head;
    Node *temp=NULL;
    Node *dummy=NULL;
    while(pos)
    {
        ptr=ptr->next;
        pos--;
    }
    cout<<ptr->prev->data<<endl;
    cout<<ptr->next->data<<endl;
    dummy->data=0;

    dummy->next=ptr->next;
    cout<<"hello"<<dummy->next->next<<endl;
    dummy->prev=ptr->prev;
    cout<<"hello"<<dummy->prev->next<<endl;
    ptr->prev->next=dummy->next;
    ptr->next->prev=dummy->prev;


}
int main()
{
    int pos;
    Node *head=createNode();
    print(head);
/*    //insert at last
    insertAtLast(head);
    print(head);
    //insert at beg
    Node *modHead=insertAtBeg(head);
    print(modHead);
    cout<<"enter position"<<endl;
    cin>>pos;
    //insert at specific position
    inserAtSpecific(head,pos);
    print(head);
*/
    //delete from specific position
    cout<<"enter position"<<endl;
    cin>>pos;
    delAtSpecific(head,pos);
    print(head);
}
