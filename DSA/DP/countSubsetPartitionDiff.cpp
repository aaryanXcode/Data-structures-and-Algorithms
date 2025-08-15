#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dp;
//recursion + memoization
int subset(vector<int>& arr,int i, int curr, int d, int target){
        if (curr > target) return 0;
    if(i==n){
        return (curr==target) ? 1: 0;
    }
    if(dp[i][curr]!=-1) return dp[i][curr];
    int take = subset(arr,i+1, curr+arr[i], d, target);
    int nottake = subset(arr,i+1, curr, d, target);
    dp[i][curr] = take+nottake;
    return dp[i][curr];
}
int countPartitions(vector<int>& arr, int d) {
    // Code here
    n = arr.size();
    
    int totalSum = accumulate(arr.begin(), arr.end(),0);
    if ((totalSum + d) % 2 != 0 || totalSum < d) return 0;
    
    int target = (totalSum + d) / 2;
    dp.assign(n+1,vector<int>(target+1,-1));
    return subset(arr, 0, 0, d, target);
}

//tabular- bottom up
int countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    
    int totalSum = accumulate(arr.begin(), arr.end(),0);
    if ((totalSum + d) % 2 != 0 || totalSum < d) return 0;
    
    int target = (totalSum + d) / 2;
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[0][0] = 1;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<= target; j++){
            dp[i][j] = dp[i-1][j];
            if(arr[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][target];
}

int main(){
    vector<int> arr = {5, 2, 6, 4};
    int d = 3;
    cout<<countPartitions(arr,d)<<endl;
}