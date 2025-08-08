#include<bits/stdc++.h>
using namespace std;


int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int maxlen = -1;
    int start = 0;
    int count = 0;
    for(int end = 0;end<n;end++){
        if(nums[end]==0) count++;
        if(count>k){
            start++;
            count--;
            maxlen = max(maxlen,end-start+1);
        }
        
        
    }
    return maxlen;
}
int main(){
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout<<longestOnes(nums,k)<<endl;
}