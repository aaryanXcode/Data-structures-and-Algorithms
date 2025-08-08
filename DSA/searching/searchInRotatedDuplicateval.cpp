#include<bits/stdc++.h>
using namespace std;

int pvt(vector<int>&nums){
        int low = 0;
        int high = nums.size()-1;
        while(low<high){
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[high]){
                low = mid+1;
            }
            else if (nums[mid] == nums[high]) {
                high--;  // shrink the search space conservatively
            }
            else{
                high = mid;
            }
        }
        return low;
    }

    bool searchHelper(vector<int>& nums,int target,int low,int high){
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]==target){
                return true;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = pvt(nums);
        if(nums[pivot]==target){
            return true;
        }
        return searchHelper(nums,target,pivot,n-1) || searchHelper(nums,target,0,pivot-1);
    }

    int main(){
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int target = 2;
    int idx = search(nums,target);
    cout<<"found at index:"<<idx<<endl;
}