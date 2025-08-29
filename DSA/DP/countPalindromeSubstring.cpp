#include<bits/stdc++.h>
using namespace std;

// Helper function to check if a substring is palindrome
bool isPalindrome(const string& s, int l, int r) {
    while(l < r) {
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

int countSubstrings(string s) {
    int n = s.size();
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(isPalindrome(s, i, j)) {
                count++;
            }
        }
    }
    return count;
}

int main(){
    string s = "abc";
    cout << countSubstrings(s) << endl; // Output: 3
}