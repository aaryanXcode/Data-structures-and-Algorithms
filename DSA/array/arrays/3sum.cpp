
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

void printArray(vector<vector<int>>&v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            cout<<v[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
}

//4sum problem
//2 loop followed by 2 sum problem
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int n1 = nums[i],n2=nums[j];
                int k = n-1;
                int l = j+1;
                while(l<k){
                    int n3=nums[l],n4=nums[k];
                    long long sum = (long long)n1+n2+n3+n4;
                    if(sum == target){
                        ans.push_back({n1,n2,n3,n4});

                        while(l<k && nums[l]==nums[l+1]) l++;
                        while(l<k && nums[k]==nums[k-1]) k--;
                        l++,k--;
                    }
                    else if(sum<target){
                        l++;
                    }else{
                        k--;
                    }
                }
            }
        }
        return ans;
    }


//a loop followed by two sum problem
//3 sum optimal
vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int n1 = nums[i];
            int j = i+1;
            int k = n-1;
            while(j<k){
                int n2 = nums[j];
                int n3 = nums[k];
                int sum = n2+n3;
                if(sum == -n1){
                    ans.push_back({n1,n2,n3});
                    while(j<k && nums[j]==nums[j+1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k-1]){
                        k--;
                    }
                    j++,k--;
                }else if (sum < -n1) {
                    j++;
                }
                else {
                    k--;
                }
                
            }
            

        }
        return ans;
    }


//brute force
vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> s;
    vector<vector<int>> ans;
    for(int i =0;i<n;i++){
        for(int j = i+1; j<n;j++){
            for(int k=j+1;k<n;k++){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0 && i!=j && i!=k && j!=k)
                {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    s.insert(triplet);
                }
            }
        }
    }
    for(auto n:s){
        ans.push_back(n);
    }
    return ans;
}


int main(){
    vector<int> nums = {2,7,11,15};
    vector<vector<int>> ans = threeSum(nums);
    printArray(ans);
}