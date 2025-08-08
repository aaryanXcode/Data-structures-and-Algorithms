#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<",";
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int longestSubarraySum(vector<int>& nums, int k) {
    int n = nums.size(),maxlen = -1;
    for(int i =0;i<n;i++){
        int sum =0;
        for(int j =i;j<n;j++){
            sum+=nums[j];
            if(sum==k){
                maxlen = max(maxlen, j-i+1);
            }
        }
    }
    return maxlen;
}

int longestSubarraySumOpt(vector<int>&nums,int k){
    int n = nums.size();
    int maxLen = -1;
    for(int i = 1;i<n;i++){
        nums[i] = nums[i-1]+nums[i];
    }
    for(int i=0;i<n;i++){
        if(nums[i]==k){
            if(maxLen<i){
                maxLen = i;
            }
        }
    }
    return maxLen+1;
}

int main(){
    vector<int> nums = {2,3,5};
    int res = longestSubarraySumOpt(nums,5);
    printArray(nums);
    cout<<"longest subarray sum:"<<res<<endl;
}