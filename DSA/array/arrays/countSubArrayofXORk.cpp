#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int>& nums){
    for(auto num:nums){
        cout<<num<<",";
    }
    cout<<endl;
}
int countSubArrayXORk(vector<int>&nums,int k){
    int n = nums.size();
    for(int i = 1;i<n;i++){
        nums[i] = nums[i-1]^nums[i];
    }
    printArray(nums);
    int count =0;
    for(int i =0;i<n;i++){
        if (nums[i] == k) {
            count++;
        }
        for (int j = i + 1; j < n; j++) {
            if ((nums[j]^ nums[i]) == k) {
                count++;
            }
        }
    }
    return count;
}

int main(){
    vector<int> nums = {4, 2, 2, 6, 4};
    int res = countSubArrayXORk(nums,6);
    cout<<res<<endl;
}