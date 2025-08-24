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

int subsec(vector<int>& nums, int i, int prev, vector<int>& ans){
    if(i==nums.size()){
        for(auto num: ans) cout<<num<<",";
        cout<<endl;
        return 0;
    }
    int take = 0;
    if(nums[i]>nums[prev]){
        ans.push_back(nums[i]);
        take = 1+subsec(nums, i+1, i, ans);
        ans.pop_back();
    }
    int nottake  = subsec(nums, i+1, prev, ans);
    return max(take,nottake);
}

int main(){
    vector<int> num =  {10,9,2,5,3,7,101,18};
    vector<int> nums;
    cout<<subsec(num, 0, -1, nums)<<endl;
    //cout<<lengthOfLIS(num)<<endl;
    return 0;
}