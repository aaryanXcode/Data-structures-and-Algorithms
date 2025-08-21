
#include<bits/stdc++.h>
using namespace std;

//recursion + memoization
int lps(string &s, int i, int j){
    if (i > j) return 0; 
    if (i == j) return 1; 
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]){
        return dp[i][j] =  2+ lps(s, i+1, j-1);
    }else{
        return dp[i][j] =  max(lps(s, i + 1, j), lps(s, i, j - 1));
    }

}
int longestPalindromeSubseq(string s) {
    n = s.size();
    dp.assign(n+1, vector<int>(n+1, -1));
    return lps(s, 0, n-1);
}

//bottom up
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(s[i-1]==s_rev[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
    string text1 = "abcde";
    string text2 = "ace";
    return longestCommonSubsequence(text1, text2);
}