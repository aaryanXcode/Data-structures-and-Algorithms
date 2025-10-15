#include<bits/stdc++.h>
using namespace std;

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    int n = nums.size();
    int start = 0;
    for(int end = 2*k-1; end<n; end++){
        int mid = start + k - 1; 
        int j = start;
        bool firstStatus = true;
        while(j<mid){
            if(nums[j]>=nums[j+1]){
                firstStatus = false;
                break;
            }
            j++;
        }
        j++;
        bool secondStatus = true;
        while(j<end){
            if(nums[j]>=nums[j+1]){
                firstStatus = false;
                break;
            }
            j++;
        }
        if(firstStatus && secondStatus){
            return true;
        }
        start++;
    }
    return false;
}
int main(){
    vector<int> nums = {2,5,7,8,9,2,3,4,3,1};
    int k = 3;
    cout<<hasIncreasingSubarrays(nums,k);
}