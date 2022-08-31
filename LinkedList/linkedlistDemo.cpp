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
        next=NULL;
    }
    void show()
    {
        cout<<data<<"->";
    }
};

int main()
{
    Node n1(1);
	n1.show();
	cout<<&n1<<"\n";
	Node *head;
	cout<<&head<<"\n";
	head=&n1;
	cout<<"address stored at head is of n1 node"<< head<<"\n";
	Node n2(2);
	n1.next=&n2;
	cout<<n1.next<<"="<<&n2<<"\n";
	cout<<"data\n";
	n1.show();
	n2.show();

}
