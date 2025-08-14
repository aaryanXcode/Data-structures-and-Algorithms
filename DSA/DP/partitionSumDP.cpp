#include<bits/stdc++.h>
using namespace std;

//tabular
bool canPartition2(vector<int>& nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(),nums.end(),0);
    if (totalSum % 2 != 0) return false;
    int target = totalSum / 2;
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
    for(int i = 0; i<=n; i++){
        dp[i][0] = true;
    }

    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=target; j++){
            if(nums[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];
}

//memoization
int n;
vector<vector<int>> dp;
bool subset(vector<int>& nums,int i,int curr, int target){
    if (curr == target) return true;
    if (i >= n || curr > target) return false;

    if(dp[i][curr]!=-1) return dp[i][curr];
    //take 
    bool take = subset(nums, i+1, curr+nums[i],target);

    //not take
    bool nottake = subset(nums, i+1, curr,target);

    dp[i][curr] = take || nottake;
    return dp[i][curr];

}

bool canPartition(vector<int>& nums) {
    n = nums.size();
    int totalSum = accumulate(nums.begin(),nums.end(),0);
    if (totalSum % 2 != 0) return false;
    int target = totalSum / 2;
    dp.assign(n+1,vector<int>(target+1,-1));
    return subset(nums, 0, 0, target);
}

int main(){
    vector<int> nums = {1,5,11,5};
    cout<<canPartition(nums);
    return 0;
}

