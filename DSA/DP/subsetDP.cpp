#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> dp;
bool subset(vector<int>& arr,const int& currSum, int sum, int i){
    if (currSum > sum) return false;
    if(i==n) {
        
        return currSum == sum;
    }
    if(dp[i][currSum]!=-1) return dp[i][currSum];
    
    bool include = subset(arr,currSum+arr[i], sum, i+1);
    bool exclude = subset(arr,currSum, sum, i+1);
    dp[i][currSum] = include || exclude;
    return dp[i][currSum];
}

bool isSubsetSum2(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));

    // Base case: sum = 0 is always true
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int s = 1; s <= sum; s++) {
            if (arr[i - 1] <= s)
                dp[i][s] = dp[i - 1][s] || dp[i - 1][s - arr[i - 1]];
            else
                dp[i][s] = dp[i - 1][s];
        }
    }

    return dp[n][sum];
}
bool isSubsetSum(vector<int>& arr, int sum) {
    n = arr.size();
    dp.assign(n+1,vector<int>(sum+1,-1));
    int currSum = 0;
    return subset(arr,currSum, sum, 0);
}

int main(){
    vector<int> arr = {3,34,4,12,5,2};
    cout<<isSubsetSum2(arr,9);
    return 0;
}