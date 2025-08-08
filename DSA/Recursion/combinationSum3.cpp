#include<bits/stdc++.h>
using namespace std;

void helper(int k,int n,int l,int r,vector<vector<int>>& ans,vector<int>& curr,vector<int>& nums){
        if(curr.size()==k)
        {
            int sum = accumulate(curr.begin(),curr.end(),0);
            if(sum==n){
                ans.push_back(curr);
            }
            return;
        }

        for(int i=l;i<r;i++){
            if(i>l && nums[i]==nums[i-1]) continue;
            curr.push_back(nums[i]);
            helper(k,n,i+1,r,ans,curr,nums);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> curr;
        helper(k,n,0,9,ans,curr,nums);
        return ans;
    }

    int main(){
        int n = 7;
        int k = 3;
        vector<vector<int>> ans = combinationSum3(k,n);
        for(auto x:ans){
            for(auto y:x){
                cout<<y<<",";
            }
            cout<<endl;
        }
    }