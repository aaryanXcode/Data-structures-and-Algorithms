#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9+7;
int specialTriplets(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;
    unordered_map<int,int> left, right;
    for(auto n: nums){
        right[n]++;
    }
    
    for(int j = 0; j<n; j++){
        right[nums[j]]--;
        long long target = nums[j]*2;
        long long leftCount = left[target];
        long long rightCount = right[target];
        ans = (ans+(leftCount*rightCount)%MOD)%MOD;
        left[nums[j]]++;
    }
    return ans;
}
int main(){
    vector<int> nums = {84,2,93,1,2,2,26};
    cout<<specialTriplets(nums)<<endl;
    return 0;
}