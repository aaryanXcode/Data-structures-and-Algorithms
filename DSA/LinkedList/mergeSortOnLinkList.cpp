/*
Before:         4 → 2 → 1 → 3
                |
Split Phase:    [4 → 2]   [1 → 3]
                |         |
                4  2      1  3
                ↓         ↓
Merge Phase:   2 → 4     1 → 3
                   \     /
                    \   /
               Final: 1 → 2 → 3 → 4
*/
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


Node* merge(Node* l1,Node* l2){
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->data > l2->data){
                tail->next = l2;
                l2 = l2->next;
            }
            else{
                tail->next = l1;
                l1 = l1->next;
            }
            tail = tail->next;
        }

        if (l1 != NULL) tail->next = l1;
        if (l2 != NULL) tail->next = l2;
        return dummy->next;
    }
    Node* midEle(Node* head){
        Node* slow = head;
        Node* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node* mergeSort(Node* head){
        if (head == NULL || head->next == NULL) return head; // Base case
        Node* mid = midEle(head);
        Node* right = mid->next;
        mid->next = NULL;
        Node* leftSortedArray = mergeSort(head);
        Node* rightSortedArray = mergeSort(right);
        return merge(leftSortedArray,rightSortedArray);
    }
    Node* sortList(Node* head) {
        return mergeSort(head);
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
    showNodes(head);
}