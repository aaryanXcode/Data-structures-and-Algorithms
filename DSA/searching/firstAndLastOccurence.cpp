//to find first and last occurence of the given target in an sorted array
//the lower bound and upper bound logic will help here 

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& nums,int target){
    int low =0;
    int high = nums.size();
    while(low<high){
        int mid = low+(high-low)/2;
        if(nums[mid]<target){
            low = mid+1;
        }else{
            high = mid;
        }
    }
    return low;
}

int upperBound(vector<int> &nums,int target){
    int low =0;
    int high = nums.size();
    while(low<high){
        int mid = low+(high-low)/2;
        if(nums[mid]<=target){
            low = mid+1;
        }else{
            high = mid;
        }
    }
    return low;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int ubd = upperBound(nums,target);
    int lbd = lowerBound(nums,target);
    if (lbd == nums.size() || nums[lbd] != target)
        return {-1, -1}; // not found
    return {lbd,ubd-1};
}

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans = searchRange(nums,target);
    for(auto num:ans){
        cout<<num<<",";
    }
}