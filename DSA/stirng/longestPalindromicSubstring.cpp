#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& str) {
        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        string res ="";
        for(int i =0;i<n;i++){
            for(int j = i;j<n;j++){
                string str = s.substr(i, j - i + 1);
                if(isPalindrome(str)){
                    if (isPalindrome(str) && str.size() > maxlen) {
                        maxlen = str.size();
                        res = str;
                    }
                }
            }
        }
        return res;
    }


    int main(){
        string s = "babad";
        cout<<longestPalindrome(s);
    }