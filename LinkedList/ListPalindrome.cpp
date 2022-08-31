#include<iostream>
using namespace std;
class ListNode
{
    public:
    int data;
    ListNode *next;
    ListNode(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
ListNode *createNode()
{
    int data;
    cin>>data;
    ListNode *head=NULL;
    ListNode *tail=NULL;
    while(data!=-1)
    {
        ListNode *newNode=new ListNode(data);
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
ListNode* middleNode(ListNode* head)
{
    int length=0;
    int mid=0;
    ListNode *ptr=head;
    if(ptr==NULL || ptr->next==NULL)
        return head;
    while(ptr!=NULL)
    {
        length++;
        ptr=ptr->next;
    }
    mid=length/2;
    ptr=head;
    if(mid%2!=0)
    {
        while(mid!=1)
        {
            ptr=ptr->next;
            mid--;
        }
        return ptr->next;
    }
    else
    {
        while(mid!=1)
        {
            ptr=ptr->next;
            mid--;
        }
        return ptr->next;

    }
}
ListNode *reverselinkedList(ListNode *head)
{
    ListNode *prev=NULL;
    ListNode *next=NULL;
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
void print(ListNode *head)
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
    ListNode *head=createNode();
    print(head);


}
