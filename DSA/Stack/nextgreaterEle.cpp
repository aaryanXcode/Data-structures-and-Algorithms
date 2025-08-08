#include<bits/stdc++.h>
using namespace std;
//circular array
int nextgreaterele(vector<int>& nums,int idx, int ele){
    int n = nums.size();
    for(int i = 1;i<n;i++){
        int ciridx = (idx+i)%n;
        if(nums[ciridx]>ele){
            return nums[ciridx];
        }
    }
    return -1;
}
int main(){
    vector<int> nums = {1,2,1};
    vector<int> ans;
    for(int i = 0;i<nums.size();i++){
        int next = nextgreaterele(nums,i,nums[i]);
        ans.push_back(next);
    }

    for(auto x:ans){
        cout<<x<<",";
    }
    cout<<endl;
}