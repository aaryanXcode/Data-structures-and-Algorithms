#include<bits/stdc++.h>
using namespace std;

int pivot(vector<int>&nums){
    int low = 0;
    int high = nums.size()-1;
    while(low<high){
        int mid = low+(high-low)/2;
        if(nums[mid]>nums[high]){
            low = mid+1;
        }else{
            high = mid;
        }
    }
    return low;
}


int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int minIdx = pivot(nums);
    cout<<"found at index:"<<minIdx<<endl;
}