
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


Node* oddEvenList2(Node* head) {
        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;
        while(even!=NULL){
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }


Node* oddEvenList(Node* head) {
        Node* ptr = head;

        Node* dummyHead = new Node(0);
        Node* dummyNode = dummyHead;

        // First pass: odd dataues
        while (ptr != NULL) {
            if (ptr->data % 2 != 0) {
                dummyNode->next = new Node(ptr->data);  // 🟢 create a new node
                dummyNode = dummyNode->next;
            }
            ptr = ptr->next;
        }

        ptr = head;
        dummyNode->next = NULL;
        // Second pass: even dataues
        while (ptr != NULL) {
            if (ptr->data % 2 == 0) {
                dummyNode->next = new Node(ptr->data);  // 🟢 create a new node
                dummyNode = dummyNode->next;
            }
            ptr = ptr->next;
        }

        dummyNode->next = NULL; // 👈 This prevents accidental cycles
        return dummyHead->next;
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
    Node* newHead = oddEvenList2(head);
    showNodes(newHead);
}

