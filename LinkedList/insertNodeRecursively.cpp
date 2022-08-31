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
    if(head!=NULL)
    {
        cout<<head->data<<"->";
        print(head->next);

    }
    else
    {
       cout<<"NULL\n";
    }

}
Node *inserNode_recursively(Node *head,int pos,int n)
{

    Node *newNode=new Node(n);
    if(head==NULL)
    {
        return head;
    }
    else if(pos==1)
    {
        newNode->next=head->next;
        head->next=newNode;
        return head;
    }
    else
    {
        head=head->next;
        inserNode_recursively(head,pos-1, n);
    }
}
int main()
{
    int data,pos;
    Node *head=createNode();
    print(head);
    cout<<"insert position\n";
    cin>>pos;
    cin>>data;
    inserNode_recursively(head,pos,data);
    print(head);
}
