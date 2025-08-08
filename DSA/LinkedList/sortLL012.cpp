
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

Node* sortZeroOneTwo(Node* head){
    Node* dummyzero = new Node(0);
    Node* dummyone = new Node(0);
    Node* dummytwo = new Node(0);
    Node* zero = dummyzero;
    Node* one = dummyone;
    Node* two = dummytwo;
    while(head!=NULL){
        if(head->data==0){
            zero->next = head;
            zero= zero->next;
        }else if(head->data ==1){
            one->next = head;
            one = one->next;
        }else{
            two->next = head;
            two = two->next;
        }
        head = head->next;
    }

    if(dummyone->next!=NULL){
        zero->next = dummyone->next;
    }else{
        zero->next = dummytwo->next;
    }
    one->next = dummytwo->next;
    two->next = NULL;
    return dummyzero->next;
}



void showNodes(Node* head){
    Node* curr = head;
    while(curr!=NULL){
        cout<<curr->data<<endl;
        curr = curr->next;
    }
    cout<<endl;
}

//function to create nodes
Node* createNodes(){
    
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data!=-1){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
    
}

int main(){
    Node* head = createNodes();
    Node* newHead = sortZeroOneTwo(head);
    showNodes(newHead);
}