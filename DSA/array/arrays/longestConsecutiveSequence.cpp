#include<bits/stdc++.h>
using namespace std;
int longestConsecutive1(vector<int>& nums) {
    int n = nums.size();
    if(n==0){
        return 0;
    }
    int ans = 1;
    unordered_set<int> s(nums.begin(),nums.end());
   
    for(auto it:nums){
        if(!s.count(it-1)){
            int count =1;
            while(s.count(it+1)){
                it++;
                count++;
            }
            ans = max(count,ans);
        }
       
    }
    return ans;
}

int longestConsecutive(vector<int>& nums) {
    if(nums.size()==0)
    {
        return 0;
    }
    sort(nums.begin(),nums.end());
    
    int ans=1;
    int previous=nums[0];
    int current=1;
    for(int i=1;i<nums.size();i++)
    {
        if(nums[i]==previous+1)
        {
            current++;
        }
        else if(nums[i]!=previous)
        {
            current=1;
        }
        previous=nums[i];
        ans=max(ans,current);
    }
    return ans;
}

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    int ans = longestConsecutive1(nums);
    cout<<ans<<endl;
}