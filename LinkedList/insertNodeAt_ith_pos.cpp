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
    Node * head=NULL;
    Node * tail=NULL;
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
int insertNode(Node *head,int pos,int n)
{
    //int count=0;
    Node *ptr=head;
    Node *newNode=new Node(n);
    pos--;
    while(pos!=1)
    {
        ptr=ptr->next;
        pos--;
    }
    newNode->next=ptr->next;
    ptr->next=newNode;

}
/*
//this is my logic
int insertNode(Node *head,int pos,int n)
{
    int count=0;
    Node *ptr=head;
    Node *newNode=new Node(n);
    count++;
    while(ptr!=NULL)
    {
        if(pos==count)
        {
            newNode->next=ptr->next;
            ptr->next=newNode;
        }
        ptr=ptr->next;
        count++;
    }


}
*/
int main()
{
    int pos;
    int dataToinsert;
    Node *head=createNode();
    print(head);
    cout<<"enter position where you want to insert data:";
    cin>>pos;
    cout<<"enter data which you want to insert there:";
    cin>>dataToinsert;
    insertNode(head,pos,dataToinsert);
    print(head);

}
