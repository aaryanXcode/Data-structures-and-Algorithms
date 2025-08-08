#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<",";
    }
}

void printArray(const vector<int> &arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int n = nums.size();
    for(int i = 0;i<nums.size()-1;i++){
        for(int j = i+1;j<n;j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> nums = {2,7,11,15};
    vector<int> ans = twoSum(nums,9);
    printArray(ans);
}