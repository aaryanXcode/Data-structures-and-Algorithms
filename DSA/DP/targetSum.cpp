#include<bits/stdc++.h>
using namespace std;
//recursion + memoization
int n , offset;
vector<vector<int>> dp;
int targetcount(vector<int>& nums, int target, int i, int curr){
    if(i==n){
        return (curr == target) ? 1: 0;
    }
    
    int idx = curr + offset; // shift to avoid negative index
    if (dp[i][idx] != -1) return dp[i][idx];
    int takepositive = targetcount(nums, target, i+1, curr+nums[i]);

    int takenegative = targetcount(nums, target, i+1, curr-nums[i]);

    return dp[i][idx] = takepositive + takenegative ;
}

int findTargetSumWays(vector<int>& nums, int target) {
    n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > totalSum) return 0;
    offset = totalSum;
    dp.assign(n+1,vector<int>(2 * totalSum +1,-1));
    return targetcount(nums, target, 0, 0);
}

//bottom up
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if (abs(target) > totalSum) return 0;
    int offset = totalSum;
    vector<vector<int>> dp(n+1,vector<int>(2*totalSum+1,0));
    dp[0][offset] = 1;
    for (int i = 1; i <= n; i++) {
        for (int sum = -totalSum; sum <= totalSum; sum++) {
            int idx = sum + offset; // shifted index
            if (dp[i - 1][idx] != 0) {
                int plusIdx = sum + nums[i - 1] + offset;
                int minusIdx = sum - nums[i - 1] + offset;
                dp[i][plusIdx] += dp[i - 1][idx];
                dp[i][minusIdx] += dp[i - 1][idx];
            } 
            
        }
        
    }
    
    if (target > totalSum || target < -totalSum) return 0;
    return dp[n][target + offset];
}

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout<<findTargetSumWays(nums, target);
}
