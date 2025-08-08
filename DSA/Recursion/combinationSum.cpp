#include<bits/stdc++.h>
using namespace std;

void combinationSum(vector<int>& nums,int l ,int r,int sum,int target,vector<int>& ans){
     if(sum==target){
        for(auto x:ans){
            cout<<x<<",";
        }
        cout<<endl;
        return;
     }

     for(int i=l;i<=r;i++){
        if (i > l && nums[i] == nums[i - 1]) continue; 
        if(sum+nums[i]> target) continue;
        ans.push_back(nums[i]);
        combinationSum(nums,i+1,r,sum+nums[i],target,ans);
        ans.pop_back();
     }
}
int main(){
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    sort(nums.begin(),nums.end());
    vector<int> ans;
    int n = nums.size()-1;
    combinationSum(nums,0,n,0,target,ans);
}

/*

1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,1,1,1,2,
1,1,1,1,1,1,1,1,
1,1,1,1,1,2,1,
1,1,1,1,1,1,1,1,
1,1,1,1,2,2,
1,1,1,1,2,1,1,
1,1,1,1,1,1,1,1,
1,1,1,2,2,1,
1,1,1,2,1,1,1,
1,1,1,1,1,1,1,1,
1,1,1,5,
1,1,2,2,2,
1,1,2,2,1,1,
1,1,2,1,1,1,1,
1,1,6,
1,1,1,1,1,1,1,1,
1,1,1,5,
1,2,2,2,1,
1,2,2,1,1,1,
1,2,1,1,1,1,1,
1,2,5,
1,7,
1,6,1,
1,1,1,1,1,1,1,1,
1,1,1,5,
2,2,2,2,
2,2,2,1,1,
2,2,1,1,1,1,
2,6,
2,1,1,1,1,1,1,
2,1,5,
7,1,
6,1,1,
1,1,1,1,1,1,1,1,
1,1,1,5,
*/