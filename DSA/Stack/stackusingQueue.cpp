#include<bits/stdc++.h>
using namespace std;

class stackusingqueue{
    queue<int> q;
    public:
        stackusingqueue(){

        }

        void push(int element){
            q.push(element);

            int size = q.size();
            // Rotate the queue to move the new element to the front
            while (size > 1) {
                q.push(q.front());
                q.pop();
                size--;
            }
        }

        void pop(){
            if (q.empty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            q.pop();
        }

        int top(){
            if (q.empty()) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            return q.front();
        }

        bool isEmpty() {
            return q.empty();
        }

        int size() {
            return q.size();
        }
}
int main(){
    StackUsingQueue st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;  // 30
    st.pop();
    cout << "Top after pop: " << st.top() << endl;  // 20
    cout << "Size: " << st.size() << endl;  // 2
    cout << "Empty? " << st.isEmpty() << endl;  // 0 (false)

}