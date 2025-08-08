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

int duplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int num : nums) {
        if (seen.count(num)) return num;
        seen.insert(num);
    }
    return -1;
}

pair<int,int> findMissing3(vector<int>& nums){
    int n = nums.size();
    int sum = n*(n+1)/2;
    int ss = (n*(n+1)*(2*n+1))/6;
    for(auto num:nums){
        sum -=num;
        ss -= num*num;
    }
    int missing = (sum + ss/sum) / 2;
    int repeating = missing - sum;
    return {missing,repeating};
}
pair<int,int> findMissing2(vector<int>& nums){
    unordered_map<int,int> map;
    for(auto num: nums){
        map[num]++;
    }
    int missing =-1;
    int duplicate = -1;
    int n = nums.size();
    for(int i =1;i<=n;i++){
        if(map[i]==0){
            missing = i;
        }

        if(map[i]==2){
            duplicate = i;
        }
    }
    return {missing,duplicate};
}
pair<int,int> findMissing(vector<int>& nums){
    //find duplicate and then find missing element
    int n = nums.size();
    int sum = n*(n+1)/2;
    int num = duplicate(nums);
    int currSum =0;
    for(int i =0;i<n;i++){
        if(nums[i]!=num){
            currSum+=nums[i];
        }
    }
    currSum = currSum + num;
    return {sum-currSum,num};
}

int main(){
    vector<int> nums = {3,1,2,5,3};
    pair<int,int> ans = findMissing3(nums);
    cout<<ans.first<<" and"<<ans.second<<endl;
}