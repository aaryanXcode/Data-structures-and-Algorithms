#include<bits/stdc++.h>
using namespace std;
void printMap(unordered_map<int,int> & map){
    for(auto n:map){
        cout<<n.first<<" "<<n.second<<endl;
    }
    cout<<endl;
}

int majorityElementUsingmoorevotingalgorithm(vector<int>& nums){
    int count =0;
    int candidate = 0;
    for(int i =0;i<nums.size();i++){
        if(count==0){
            candidate = nums[i];
        }
        if(candidate==nums[i]){
            count ++;
        }
        else{
            count --;
        }
    }
    return candidate;
}
int majorityElement(vector<int>& nums) {
    unordered_map<int,int> map;
    for(auto n:nums){
        map[n]++;
    }
    printMap(map);
    int max = -1;
    int res = 0;
    for(auto x:map){
        if(max<x.second){
            max = x.second;
            res = x.first;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {3,2,3};
    int res = majorityElementUsingmoorevotingalgorithm(nums);
    cout<<"Majority element is: "<<res<<endl;
}