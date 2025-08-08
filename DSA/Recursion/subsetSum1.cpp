#include<bits/stdc++.h>
using namespace std;

void subsetSum1(vector<int>& nums,int sum,int n,int i){
    if(i==n)
    {
        cout<<sum<<","<<endl;
        return ;
    }

    //pick 
    subsetSum1(nums,sum+nums[i],n,i+1);

    //not pick
    subsetSum1(nums,sum,n,i+1);
}

int main(){
    vector<int> nums = {3,2,1};
    int n = nums.size();
    subsetSum1(nums,0,n,0);
    return 0;
}