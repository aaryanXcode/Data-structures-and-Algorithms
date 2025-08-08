#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>&nums){
    for(auto n: nums){
        cout<<n<<",";
    }
    cout<<endl;
}
int longestSubarraySumOpt(vector<int>&nums,int k){
    int n = nums.size();
    int maxLen = -1;
    for(int i = 1;i<n;i++){
        nums[i] = nums[i-1]+nums[i];
    }
    printArray(nums);
    for(int i =0;i<n;i++){
        if (nums[i] == k) {
            maxLen = max(maxLen, i + 1);
        }
        for (int j = i + 1; j < n; j++) {
            if (nums[j] - nums[i] == k) {
                maxLen = max(maxLen, j - i);
            }
        }
    }
    return maxLen;
}
int main(){
    vector<int> nums = {9, -3, 3, -1, 6, -5};
    int res = longestSubarraySumOpt(nums,0);
    cout<<res<<endl;
}