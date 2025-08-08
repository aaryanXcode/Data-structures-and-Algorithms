#include<bits/stdc++.h>
using namespace std;

class dstack{
    int *data;
    int nextindex;
    int capacity;

    public:
        dstack(){
            data = new int[4];
            capacity = 4;
            nextindex =0;
        }

        void push(int element){
            if(capacity==nextindex){
                int *newData = new int[2*capacity];
                for(int i=0;i<capacity;i++){
                    newData[i] = data[i];
                }
                capacity = 2*capacity;
                delete data;
                data = newData;
            }
            data[nextindex] = element;
            nextindex++;
        }

        void pop(){
            if(isEmpty()){
                cout<<"stack is empty"<<endl;
            }
            nextindex--;
        }

        int top(){
            if(isEmpty()){
                cout<<"stack is empty"<<endl;
            }
            return data[nextindex-1];
        }

        bool isEmpty(){
            return nextindex == 0;
        }

        int size(){
            return nextindex;
        }
};

int main(){
    dstack st;
    st.push(4);
    st.push(3);
    st.push(1);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);

    cout<<st.top()<<endl;
    cout<<st.size()<<endl;

    while(!st.isEmpty()){
        cout<<st.top()<<",";
        st.pop();
    }
    cout<<endl;
    cout<<st.size()<<endl;
}