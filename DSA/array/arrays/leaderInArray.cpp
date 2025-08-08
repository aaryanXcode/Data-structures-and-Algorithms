#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int>& nums){
    int n = nums.size();
    for(int i = 0;i<n;i++){
        cout<<nums[i]<<",";
    }
    cout<<endl;
}
int findGreater(vector<int>& nums,int i){
    int mx = 0;
    int n = nums.size();
    for(int j =i+1;j<n;j++){
        mx = max(mx,nums[j]);
    }
    return mx;
}
vector<int> findLeader(vector<int>& nums){
    vector<int> ans;
    int n = nums.size();
    for(int i =0;i<n;i++){
        bool isLeader = true;
        for (int j = i + 1; j < n; j++) {
            cout<<"nums[j]"<<nums[j]<<" , nums[i]"<<nums[i]<<endl;
            if (nums[j] >= nums[i]) {
                isLeader = false;
                break;
            }
        }
        if (isLeader) {
            ans.push_back(nums[i]);
        }
    }
    
    return ans;
}

int main(){
    vector<int> nums = {4,7,1,0};
    vector<int> ans = findLeader(nums);
    printArray(ans);
}