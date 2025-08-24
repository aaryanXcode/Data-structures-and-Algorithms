#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
bool isPredecessor(string& a, string& b){
    int n = a.size();
    int m = b.size();
    if(n+1 != m){
        return false;
    }
    int i = 0, j = 0;
    int mismatch  = 0;

    while(i<n && j<m){
        if(a[i]==b[j]){
            i++,j++;
        }
        else{
            mismatch++;
            if(mismatch>1) return false;
            j++;
        }
    }
    return true;
}
int lsc(vector<string>& words, int i, int prev){
    if(i==words.size()) return 0;
    if(dp[i][prev+1]!=-1) return -1;
    int take = 0;

    if(prev==-1 || isPredecessor(words[prev],words[i])){
        take = 1+lsc(words, i+1, i);
    }

    int nottake = lsc(words, i+1, prev);
    return dp[i][prev+1] = max(take, nottake);
}
int longestStrChain(vector<string>& words) {
    auto comp = [](const string& a, const string &b){
        return a.size()<b.size();
    };
    sort(words.begin(), words.end(), comp);
    int n = words.size();
    dp.assign(n, vector<int>(n+1,-1));
    return lsc(words, 0, -1);
}

int main(){
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    cout<<longestStrChain(words);
    return 0;
}