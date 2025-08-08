#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>&nums){
    for(auto num:nums){
        cout<<num<<",";
    }
    cout<<endl;
}
int lowerBound(vector<int>&nums,int x){
    int low =0;
    int high = nums.size()-1;
    while(low<high){
        int mid = low+(high-low)/2;
        if(nums[mid]<x){
            low = mid+1;
        }
        else{
            high = mid;
        }
    }
    return low;
}

int main(){
    vector<int> nums = {1,2,2,3};
    int lowerBounnd = lowerBound(nums,2);
    cout<<"lower Bound:"<<lowerBound<<endl;
}