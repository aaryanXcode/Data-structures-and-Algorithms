#include<bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}



string postfixex(string& infix){
    stack<char> st;
    string output = "";
    for(int i =0;i<infix.size();i++){
        char c = infix[i];
        if((c >= 65 && c<= 90) || (c>=97 && c<=122)){
            output += c;
        }else if(c=='('){
            st.push(c);
        }
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                if(st.top()!='(')
                {
                    output += st.top();
                    st.pop();
                }
            }
            if(st.top()=='('){
                st.pop();
            }
        }
        else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
            while (!st.empty() && st.top() != '(' &&
                (precedence(c) < precedence(st.top()) || 
                (precedence(c) == precedence(st.top()) && c != '^'))) {
                output += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        output +=st.top();
        st.pop();
    }
    return output;
}
int main(){
    string infix = "(p+q)*(m-n)";
    string postfix  = postfixex(infix);
    cout<<postfix<<endl;
}

/*
function infixToPostfix(expression):
    create empty stack 'st' for operators
    create empty string 'output'

    for each character 'ch' in expression:
    
        if ch is operand:
            append ch to output

        else if ch is '(':
            push ch to stack

        else if ch is ')':
            while top of stack is not '(':
                pop from stack and append to output
            pop '(' from stack (discard it)

        else if ch is operator (+, -, *, /, ^):
            while stack is not empty AND top is not '(' AND
                  (precedence(ch) < precedence(top of stack) OR
                   precedence(ch) == precedence(top of stack) AND ch is left-associative):
                pop from stack and append to output
            push ch to stack

    while stack is not empty:
        pop from stack and append to output

    return output
*/