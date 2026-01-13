#include<bits/stdc++.h>
using namespace std;

string decodeString(string s) {
    stack<char> st;
    string res = "";
    for(auto c: s){
        if(c==']'){
            string temp ="";
            while(!st.empty() && st.top()!='['){
                temp = st.top() + temp;
                st.pop();
            }
            st.pop(); 
            string numStr = "";
            while(!st.empty() && isdigit(st.top())){
                numStr = st.top() + numStr;
                st.pop();
            }
            int num = stoi(numStr);
            for(int i = 0; i<num; i++){
                for(auto ch : temp){
                    st.push(ch);
                }
            }
        }else{
            st.push(c);
        }
    }
    while(!st.empty()){
        res = st.top() + res;
        st.pop();
    }
    return res;
}
int main(){
    string s = "3[a]2[bc]";
    cout<<decodeString(s);
    return 0;
}