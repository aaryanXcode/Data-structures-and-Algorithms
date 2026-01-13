#include<bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
        stack<string> st;
        string dir = "";
        string dot = "";
        for(auto c : path){
            
            if(c!='.' && c!='/'){
                dir +=c;
            }
            else if(c=='.'){
                dot += c;
            }
            else if(c=='/'){
                if(dot.size()==2 && !st.empty()){
                    st.pop();
                    dot = "";
                }
                else if(dot.size()>2){
                    st.push(dot);
                    dot = "";
                }
                else if(!dir.empty()){
                    st.push(dir);
                    dir = "";
                    dot = "";
                } 
                else if(dot.size()==2){
                    dot = "";
                }
            }
            
        }
        if(!dir.empty()){
            st.push(dir);
        }
        if(!dot.empty() && dot.size()==2){
            st.pop();
        }else if(dot.size()>2){
            st.push(dot);
        }
        string abspath = "";
        while(!st.empty()){
            string top = "/"+st.top();
            abspath = top + abspath;
    
            st.pop();
        }


        
        return abspath.empty()?"/":abspath;;
    }

string simplifyPath2(string path) {
    stack<string> st;
    string part = "";   // accumulate one directory name between slashes

    for (int i = 0; i <= path.size(); i++) {
        char c = (i < path.size() ? path[i] : '/'); // treat end as slash

        if (c == '/') {
            if (part.empty()) continue;  // skip multiple slashes

            if (part == ".") {
                // do nothing (current directory)
            } 
            else if (part == "..") {
                if (!st.empty()) st.pop(); // go up one directory
            } 
            else {
                st.push(part); // normal folder (includes "...", etc.)
            }
            part.clear();
        } 
        else {
            part += c; // build the current segment
        }
    }

    // build final canonical path
    string result = "";
    while (!st.empty()) {
        result = "/" + st.top() + result;
        st.pop();
    }

    return result.empty() ? "/" : result;
}


    int main(){
        string path = "/home//foo/";
        string abspath = simplifyPath2(path);
        cout<<abspath<<endl;
    }