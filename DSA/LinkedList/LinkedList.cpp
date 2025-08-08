#include<bits/stdc++.h>
using namespace std;


/*
                _________________
    Node  -->   |  data  |  *next|
                |________|_______|

*/

class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

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
    showNodes(head);
}