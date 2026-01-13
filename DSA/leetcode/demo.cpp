#include<iostream>
using namespace std;

bool isSubsequence(string s, string t) {
    int n = s.size();
    int m = t.size();
    int i = 0, j = 0;
    while(j<m){
        if(s[i]==t[j]){
            i++; 
        }
        j++;
    }
    if(i==n){
        return true;
    }
    return false;
}
int main(){
    string s = "abc";
    string t = "ahbgdc";
    cout<<isSubsequence(s,t);
}