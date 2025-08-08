#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>&nums){
    for(auto num:nums){
        cout<<num<<",";
    }
    cout<<endl;
}

pair<int,int> floorCeil(vector<int>&nums,int target){
    int low =0,high = nums.size()-1;
    int floor =-1;
    int ceil =-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]==target){
            return {low,high};
        }else if(nums[mid]>target){
            ceil = nums[mid];
            high = mid-1;
        }else{
            floor = nums[mid];
            low = mid+1;
        }
    }
    return {floor,ceil};
}

int main(){
    vector<int> nums = {3, 4, 4, 7, 8, 10};
    pair<int,int> ans= floorCeil(nums,5);
    cout<<"floor:"<<ans.first<<","<<"ceil:"<<ans.second<<endl;
}