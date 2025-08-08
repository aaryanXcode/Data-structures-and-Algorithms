#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    
    Node(int element){
        val = element;
        next = nullptr;
    }
};

class stackList{
        
    
    public:
        Node* top;
        int currentsize;
        stackList(){
            top = nullptr;
            currentsize =0;
        }

        void push(int element){
            Node* newNode = new Node(element);
            newNode->next = top;
            top = newNode;
            currentsize++;
        }

        void pop(){
            if(top==nullptr){
                cout<<"stack is empty"<<endl;
                return;
            }
            Node* temp = top;
            top = top->next;
            delete temp; 
            currentsize--;
        }

        int front(){
            if (top == nullptr) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return top->val;
        }

        bool isEmpty(){
            if(top==nullptr){
                return true;
            }
            return false;
        }

        int size(){
            return currentsize;
        }
        ~stackList() {
            while (!isEmpty()) {
                pop();  // clean up memory
            }
        }
};
int main(){
    stackList s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.front() << endl;  // 30
    s.pop();
    cout << "Top after pop: " << s.front() << endl;  // 20
    cout << "Size: " << s.size() << endl;  // 2
    cout << "Empty? " << s.isEmpty() << endl;
}