#include<bits/stdc++.h>
using namespace std;
//basic linkedlist
class SinglyLinkedList{
    //singlylinnkedlist stores a array of type integer and a pointer to the next linkedlist
    private:
        int num;
        SinglyLinkedList* next;
    public:
        SinglyLinkedList(int n,SinglyLinkedList* l){
            this->num = n;
            this->next = l;
        }

        int getVal(){
            if (this == NULL) return -1;  // or -1 or any agreed dummy value
            return this->num;
        }

        void setNum(int num){
            this->num = num;
        }

        SinglyLinkedList* getNext() {
            return next;
        }

        void setNext(SinglyLinkedList* nxt) {
            next = nxt;
        }

};

int main(){
    SinglyLinkedList* list = new SinglyLinkedList(4,NULL);
    SinglyLinkedList* list1 = new SinglyLinkedList(5,NULL);
    SinglyLinkedList* list2 = new SinglyLinkedList(6,NULL);
    SinglyLinkedList* list3 = new SinglyLinkedList(7,NULL);
    SinglyLinkedList* list4 = new SinglyLinkedList(8,NULL);
    list->setNext(list1);
    list1->setNext(list2);
    list2->setNext(list3);
    list3->setNext(list4);

    SinglyLinkedList* curr = list;
    while (curr != nullptr) {
        cout << curr->getVal() << endl;
        curr = curr->getNext();
    }

    // Clean up
    delete list4;
    delete list3;
    delete list2;
    delete list1;
    delete list;

    return 0;

}

