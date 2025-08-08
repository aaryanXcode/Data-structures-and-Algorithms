#include<bits/stdc++.h>
using namespace std;

//solve it using stack it will be optimized, i used queue
class MinStack {
    int minm;
    queue<int> q;
public:
    MinStack() {
        minm = INT_MAX;
    }
    
    void push(int val) {
        q.push(val);
        minm = min(minm,val);
        int size = q.size();
        while(size>1){
            q.push(q.front());
            q.pop();
            size--;
        }
    }
    
    void pop() {
        if(q.empty()){
            return ;
        }
        queue<int> tempq = q;
        int removed = q.front();
        q.pop();

        if (removed == minm) {
            minm = INT_MAX;
            queue<int> tempq = q;
            while (!tempq.empty()) {
                minm = min(minm, tempq.front());
                tempq.pop();
            }
        }
    }
    
    int top() {
        if(q.empty()){
            return 0;
        }
        return q.front();
    }
    
    int getMin() {
        return minm;
    }
};

int main(){
    MinStack st;
    st.push(-2);
    st.push(0);
    st.push(-3);
    cout<<st.getMin()<<endl;
    st.pop();
    cout<<st.top()<<endl;
    cout<<st.getMin()<<endl;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */