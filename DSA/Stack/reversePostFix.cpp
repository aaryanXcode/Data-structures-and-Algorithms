#include<bits/stdc++.h>
using namespace std;

int cal(int A, int B, string op) {
    if (op == "+") return A + B;
    if (op == "-") return A - B;
    if (op == "*") return A * B;
    return A / B;
}
int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto c : tokens) {
        if (c == "+" || c == "-" || c == "*" || c == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            st.push(cal(a, b, c));
        } else {
            st.push(stoi(c));
        }
    }
    return st.top();
}

    
int main() {
    vector<string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(tokens);
    return 0;
}
