#include<bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    while(nums.size()>1){
        vector<int> newNums(nums.size()-1);
        int i =0;
        int j = 0;
        while(i<nums.size()-1){
            newNums[j] = (nums[i]+nums[i+1])%10;
            i++;
            j++;
        }
        nums = newNums;
        
    }
    return nums[0];
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5};
    cout<<triangularSum(nums);
    return 0;
}