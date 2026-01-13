#include<bits/stdc++.h>
using namespace std;


int cal(int A, int B, string op) {
    if (op == "+") return A + B;
    if (op == "-") return A - B;
    if (op == "*") return A * B;
    return A / B;
}

int evalRPN(vector<string>& tokens){
    stack<int> st;
    for(auto c: tokens){
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

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infixToPostfix(string& infix) {
    stack<char> st;
    string output = "";

    for (int i = 0; i < infix.size(); i++) {
        char c = infix[i];
        if (c == ' ') continue;

        // ✅ Handle multi-digit numbers
        if (isdigit(c)) {
            string num = "";
            while (i < infix.size() && isdigit(infix[i])) {
                num += infix[i];
                i++;
            }
            output += num + " ";
            i--; // step back
        }

        else if (c == '(') {
            st.push(c);
        }

        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                output += st.top();
                output += ' ';
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop();
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            while (!st.empty() && st.top() != '(' &&
                   (precedence(c) < precedence(st.top()) ||
                   (precedence(c) == precedence(st.top()) && c != '^'))) {
                output += st.top();
                output += ' ';
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        output += st.top();
        output += ' ';
        st.pop();
    }

    return output;
}



int calculate(string s) {
    string postfix = infixToPostfix(s);
    stringstream ss(postfix);
    string tokenStr;
    vector<string> tokens;

    while (ss >> tokenStr) tokens.push_back(tokenStr);

    return evalRPN(tokens);
}

int main() {
    string s = "1-(     -2)";
    cout << calculate(s);
    return 0;
}

