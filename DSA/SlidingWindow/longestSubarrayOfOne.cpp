#include<bits/stdc++.h>
using namespace std;


int longestSub(vector<int>& nums){
    int n = nums.size();
    int start = 0;
    int maxCount = INT_MIN;
    int k = 0;
    for(int end = 0; end<n; end++){
        if(nums[end]==0) k++;
        while(k>1){
            if(nums[start]==0){
                k--;
                start++;
            }else{
                start++;
            }

        }
        maxCount = max(maxCount, end-start);
    }
    cout<<maxCount<<endl;
    return maxCount;
} 
int longestSubarray(vector<int>& nums) {
    return longestSub(nums);
}
int main(){
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    cout<<longestSubarray(nums)<<endl;
    return 0;
}