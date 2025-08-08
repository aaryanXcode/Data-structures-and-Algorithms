#include<bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
        int max = -1;
        int count = 0;
        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }else{
                if(s[i]==')'){
                    if(max<count){
                        max = count;
                    }
                    count--;
                }
               
            }
        }
        return max;
    }
int main(){
    string s = "(1+(2*3)+((8)/4))+1";
    cout<<maxDepth(s);
}