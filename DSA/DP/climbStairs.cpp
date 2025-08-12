#include<bits/stdc++.h>
using namespace std;

 vector<int> dp;

 //memoization
int climbHelper(int n){
    if(n<0) return 0;
    if(n==0){
        return 1;
    }
    if(dp[n]!=-1) return dp[n];
    dp[n]= climbHelper(n-1) + climbHelper(n-2);
    return dp[n] ;
}

//tabular form
int climbStairs(int n) {
    if(n<=1) return 1;
    dp.assign(n+1,-1);
    dp[0] = dp[1] = 1;
    for(int i =2; i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main(){
    int n = 5;
    cout<<climbStairs(n);
    return 0;
}
