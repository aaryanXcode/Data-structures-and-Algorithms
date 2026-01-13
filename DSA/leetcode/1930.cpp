#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int i, int j){
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int countSubPalindrome(string &s, int l, int r){
    if(l==r){
        return 0;
    }
    
    

}
int main(){
    string s = "aabca";
    int n = s.size();
    cout<<countSubPalindrome(s, 0, n);
    return 0;
}