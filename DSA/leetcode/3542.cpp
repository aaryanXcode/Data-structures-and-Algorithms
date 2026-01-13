#include<bits/stdc++.h>
using namespace std;
void makeitzero(int ele, vector<int>& nums) {
    for (int& x : nums)
        if (x == ele)
            x = 0;
}

int minOperations(vector<int>& nums) {
    set<int> s; 
    int n = nums.size();
    for(auto n : nums){
        s.insert(n);
    }
    int count = 0;
    for (int ele : s) {
        makeitzero(ele, nums);
        count++;
    }
    return count;
}

int main(){
    vector<int> nums = {3,1,2,1};
    cout<<minOperations(nums);
    return 0;
}