

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

void sortColors(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = 0;
    int k = n-1;
    while(j<=k){
        if(nums[j]==1){
            j++;
        }else if(nums[j]==2){
            swap(nums[j],nums[k]);
            k--;
        }else{
            swap(nums[i],nums[j]);
            i++;
            j++;
        }
    }
}

int main(){
    vector<int> nums = {1,0,1,2,2,0};
    sortColors(nums);
    printArray(nums);
}