#include<bits/stdc++.h>
using namespace std;
//implementation of stack using array
class StackUsingArray{
    private:
        int *data;
        int nextindex;
        int capacity;
    public:
        StackUsingArray(int totalsize){
            data = new int[totalsize];
            nextindex =0;
            capacity = totalsize;
        }

        int size(){
            return nextindex;
        }

        void push(int element){
            if(nextindex==capacity){
                cout<<"stack is full"<<endl;
                return ;
            }
            data[nextindex] = element;
            nextindex++;
        }

        int pop(){
            if(isEmpty()){
                cout<<"stack is empty"<<endl;
                return INT_MIN;
            }
            nextindex--;
            return data[nextindex];
        }

        int top(){
            if(isEmpty()){
                cout<<"stack is empty"<<endl;
                return INT_MIN;
            }
            return data[nextindex-1];
        }

        bool isEmpty(){
            return nextindex==0;
        }
};

int main(){
    StackUsingArray st(4);
    st.push(4);
    st.push(3);
    st.push(1);
    st.push(4);

    cout<<st.top()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.size()<<endl;
    cout<<st.isEmpty()<<endl;
    cout<<st.top()<<endl;
}