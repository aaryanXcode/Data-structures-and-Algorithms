#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
Node * takeInput()
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
        else{
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
    cout<<"NULL";
}
/*int palindrome(Node * head)
{
    int sum1=0;
    int sum2=0;
    Node *slow =head;
    Node *fast=head;
    while(fast->next!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"mid of linked list"<<slow->data<<endl;
    while(head!=slow->next)
    {
        sum1+=head->data;
        head=head->next;
    }
    cout<<"sum of head to slow "<<sum1<<endl;
    while(slow!=fast->next)
    {
        sum2+=slow->data;
        slow=slow->next;
    }
    cout<<"sum of slow to fast "<<sum2<<endl;

}
*/
int isPalindrome(Node *head) {
    // Write your code here.

    Node *slow=head;
    Node *fast=head;
    Node *mid=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"mid"<<mid->data<<endl;
    mid=slow->next;
    cout<<"mid"<<mid->data<<endl;
    slow=NULL;
    //reversin mid to end;
    Node *prev=NULL;
    Node *next=NULL;
    while(mid!=NULL)
    {
        next=mid->next;
        mid->next=prev;
        prev=mid;
        mid=next;
    }
    mid=prev;
    cout<<"printing mid to end"<<endl;
    while(mid!=NULL)
    {
        cout<<mid->data<<"->";
        mid=mid->next;
    }
    cout<<"NULL"<<endl;
    cout<<"printing head to mid"<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
    while(head!=NULL || head->next!=NULL )
    {
        if(head==mid)
        {
            cout<<head->data;
            head=head->next;
            mid=mid->next;
        }
        else
            cout<<"not matched"<<endl;

    }



}
Node *rotate(Node *head, int k)
{

    Node *ptr=head;
    Node *newHead=head;
    Node *countPtr=head;
    Node *temp=NULL;
    Node *temp2=NULL;
    int length=0;
    while(countPtr!=NULL)
    {
        countPtr=countPtr->next;
        length++;
    }
    cout<<"\nlength="<<length<<endl;
    while(ptr->next!=NULL)
    {

        ptr=ptr->next;
    }
    ptr->next=head;
    int n=length-k;
    cout<<"value of n="<<n<<endl;
    while(n!=0)
    {
        temp2=newHead;
        newHead=newHead->next;
        n--;
    }
    while(head!=temp2)
    {
        head=head->next;
    }
    head->next=NULL;
    return newHead;
}

int main()
{
    Node * head=takeInput();
    print(head);
   // isPalindrome(head);
    Node *newHead=rotate(head, 4);
    print(newHead);
}
