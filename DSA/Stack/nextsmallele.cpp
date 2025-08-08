#include<bits/stdc++.h>
using namespace std;

int nextSmallele(vector<int>& nums,int idx,int ele){
    for(int i = idx;i<nums.size();i++){
        if(nums[i]<ele){
            return nums[i];
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,8,5,2,25};
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            int nextsme = nextSmallele(nums,i,nums[i]);
            mp.insert({nums[i],nextsme});
        }
        for(int i=0;i<nums.size();i++){
            auto it = mp.find(nums[i]);
            if(it!=mp.end()){
                ans.push_back(it->second);
            }
        }

    for(auto x: ans){
        cout<<x<<",";
    }
    cout<<endl;
}
/*
Input: arr = [4, 8, 5, 2, 25]

Output: [2, 5, 2, -1, -1]
*/