#include<bits/stdc++.h>
using namespace std;

class DoublyLinkedlist{
    public:
        DoublyLinkedlist* prev;
        DoublyLinkedlist* next;
        int val;
    
        DoublyLinkedlist(int d){
            this->prev = NULL;
            this->val = d;
            this->next = NULL;
        }
};

DoublyLinkedlist* createNode(){
    int data ;
    cin>>data;
    DoublyLinkedlist* head=NULL;
    DoublyLinkedlist* tail = NULL;
    while(data !=-1){
        if(head==NULL){
            head = new DoublyLinkedlist(data);
            tail = head;
        }
        else{
            DoublyLinkedlist* newNode = new DoublyLinkedlist(data);
            newNode->prev = tail;
            tail->next = newNode;
            tail = tail->next;
        }
        cin>>data;
    }
    return head;
}


void printNode(DoublyLinkedlist* head){
    while(head != NULL){
        cout << head->val;
        if (head->next != NULL) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}
int main(){
    DoublyLinkedlist* head = createNode();
    printNode(head);
}