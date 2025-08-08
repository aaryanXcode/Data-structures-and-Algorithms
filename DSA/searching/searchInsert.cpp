#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>&nums){
    for(auto num:nums){
        cout<<num<<",";
    }
    cout<<endl;
}

int searchInsert(vector<int>&nums,int x){
    int low =0;
    int high = nums.size()-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]==x){
            return mid;
        }
        else if(x>nums[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return low;
}

int main(){
    vector<int> nums = {1,2,2,3};
    int up = searchInsert(nums,2);
    cout<<"element loc should be at or found at :"<<up<<endl;
}