#include<bits/stdc++.h>
using namespace std;

void subsettwo(vector<int>& nums,int start,int n,vector<int>& curr){
    
    for(auto x:curr){
        cout<<x<<",";
    }
    cout<<endl;
        
  
    //pick
    for(int i = start;i<n;i++){
        if(i> start && nums[i]==nums[i-1]) continue ;
        curr.push_back(nums[i]);
        subsettwo(nums,i+1,n,curr);
        curr.pop_back();
    }
    
    //not pick
   
}

int main(){
    vector<int> nums = {1,2,2};
    int n = nums.size();
    vector<int> curr;
    sort(nums.begin(),nums.end());
    subsettwo(nums,0,n,curr);
}