#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int n){
    int size = s.size();
    if (n >= size / 2) return true;

    if (s[n] != s[size - 1 - n]) return false;

    return isPalindrome(s, n + 1);
}

int main(){
    string s = "eye";
    int n  = s.length();
    bool res = isPalindrome(s,n);
    cout<<"is palindrome:"<<res<<endl;
}