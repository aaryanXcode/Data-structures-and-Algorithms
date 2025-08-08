//followup question of sort recursion using stack trying to practice problem related to that 
//so that i get clarity of recursive algo thinking and it helps in stack topic

#include<bits/stdc++.h>
using namespace std;
void printStack(stack<int>& st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<endl;
}


void insertElementAtBottom(stack<int>& st,int val){
    if(st.empty()){
        st.push(val);
        return;
    }
    int num = st.top();
    st.pop();
    insertElementAtBottom(st,val);
    st.push(num);
}
void reverseStack(stack<int>& st){
    if(st.empty()){
        return; 
    }
    int top = st.top();
    st.pop();
    reverseStack(st);
    insertElementAtBottom(st,top);
}

void insertElementAtCorrectPosition(stack<int>& st,int val){
    if(st.empty() || val>st.top()){
        st.push(val);
        return;
    }
    int currTop = st.top();
    st.pop();
    insertElementAtCorrectPosition(st,val);
    st.push(currTop);

}
void sortStack(stack<int>& st){
    if(st.empty())
        return;
    int top = st.top();
    st.pop();
    sortStack(st);
    insertElementAtCorrectPosition(st,top);
}

int main(){
    
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(2);
    st.push(1);
    //sortStack(st); //just for practice
    reverseStack(st);  //using another stack we can do that but let see recursion as stack
    printStack(st);
    return 0;
}