#include<bits/stdc++.h>
using namespace std;
void printStack(stack<int>& st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<endl;
}
void insertSt(stack<int> &st, int val){
    if(st.empty() || val<st.top()){
        st.push(val);
        return;
    }
    int currtop = st.top();
    st.pop();
    
    insertSt(st,val);
    st.push(currtop);
}
void sortStack(stack<int> &st){
    if(st.empty()) return;
    int top = st.top();
    cout<<top<<endl;
    st.pop();
    sortStack(st);
    
    insertSt(st,top);

}

int main(){
    
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(2);
    st.push(1);
    sortStack(st);
    printStack(st);
    return 0;
}

