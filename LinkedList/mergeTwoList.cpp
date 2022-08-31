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
    Node *Head=NULL;
    Node *tail=NULL;
    while(data!=-1)
    {
        Node *newNode=new Node(data);
        if(Head==NULL)
        {
            Head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return Head;
}
Node *mergeTwoList(Node *listA,Node *listB)
{
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(listA && listB ==NULL)
    {
        if(listA->data<=listB->data)
        {
            if(head==NULL)
            {
                head=listA;
                tail=listA;
            }
            else
            {
                tail->next=listA;
                tail=tail->next;
            }
        }
        else
        {
            if(head==NULL)
            {
                head=listA;
                tail=listA;
            }
            else
            {
                tail->next=listB;
                tail=tail->next;
            }
        }
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
int main()
{
    Node *listA=createNode();
    Node *listB=createNode();
    print(listA);
    print(listB);
    Node *listC=mergeTwoList(listA,listB);
    print(listC);

}
