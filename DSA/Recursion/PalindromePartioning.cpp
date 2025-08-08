#include<bits/stdc++.h>
using namespace std;
bool isPalindrome(string& s,int l,int r){
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void helper(vector<vector<string>>& ans,string& s,int l,int r,vector<string>& temp){
        if(l==r){
            ans.push_back(temp);
            return;
        }
        for (int i = l; i < r; ++i) {
            if (isPalindrome(s, l, i)) {
                temp.push_back(s.substr(l, i - l + 1));
                helper(ans,s,i+1,r,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if(s.empty()) return ans;
        int r = s.size();
        vector<string> temp;
        helper(ans,s,0,r,temp);
        return ans;

    }

    int main(){
        string s ="aab";
        vector<vector<string>> ans = partition(s);
        for(auto x:ans){
            for(auto y:x){
                cout<<y<<",";
            }
            cout<<endl;
        }
    }