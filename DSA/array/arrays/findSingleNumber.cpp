#include<bits/stdc++.h>
using namespace std;


int singleNumber(vector<int>& nums) {
    int n = nums.size();
    if(nums.size()==1){
        return nums[0];
    }
    int res = 0;
    for(int i=0;i<n;i++){
        res ^= nums[i];
    }
    return res;
}

int main(){
    vector<int> nums = {4,1,2,1,2};
    int res = singleNumber(nums);
    cout<<"Single Number:"<<res<<endl;
}