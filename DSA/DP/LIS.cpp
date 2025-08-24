#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> dp;

int lis(vector<int>& nums, int i, int prev){
    if(i==nums.size()) return 0;
    if(i==prev) return 0;
    if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    int nottake = lis(nums, i+1, prev);

    int take = 0;
    if(prev==-1 || nums[i]>nums[prev])
    {
        take = 1+lis(nums, i+1, i);
    }

    return dp[i][prev+1] = max(take,nottake);

}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    dp.assign(n, vector<int>(n+1, -1));
    return lis(nums, 0, -1);
}

int bottomUp(vector<int>& nums){
    
    int n = nums.size();
    vector<int> dp(n,1);

    for(int i =0; i<n; i++){
        for(int j = 0; j<i ; j++){
            if(nums[i]>nums[j]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
    }

    return dp[n-1];
}
int main(){
    vector<int> num =  {10,9,2,5,3,7,101,18};
    cout<<bottomUp(num)<<endl;
    cout<<lengthOfLIS(num)<<endl;
    return 0;
}