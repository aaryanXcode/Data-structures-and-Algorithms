#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> dp;
//recursive + memoization
int countsubet(vector<int>& arr, int i, int curr, int target){
    if(i==n){
        return (curr==target) ? 1 : 0;
    }
    
    if(curr>target) return 0;
    
    if(dp[i][curr]!=-1) return dp[i][curr];
    
    int take = countsubet(arr, i+1, curr+arr[i], target);
    
    int nottake = countsubet(arr, i+1, curr, target);
    
    dp[i][curr] = take+nottake;
    return dp[i][curr];
}
int perfectSum(vector<int>& arr, int target) {
    // code here
    n = arr.size();
    dp.assign(n+1,vector<int>(target+1,-1));
    return countsubet(arr, 0 , 0, target);
}

//tabular form
int perfectSum(vector<int>& arr, int target) {
        // code here
    int n = arr.size();
    const int MOD = 1e9+7;
    vector<vector<int>> dp(n+1,vector<int>(target+1,0));
    dp[0][0] = 1;
    
    for(int i = 1; i<=n; i++){
        for(int j = 0 ; j<=target; j++){
            dp[i][j] = dp[i - 1][j];                // exclude arr[i-1]
            if (arr[i - 1] <= j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - arr[i - 1]]) % MOD; // include
            }
        }
    }
    return dp[n][target];
    
}

int main(){
    
    vector<int> arr = {5,2,3,10,6,8};
    n = arr.size();
    cout<<perfectSum(arr,10)<<endl;
    
}