#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int>& nums){
    int n  = nums.size();
    for(int i = 0;i<n;i++){
        cout<<nums[i]<<",";
    }
    cout<<endl;
}
void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;  // ✅ Nothing to do

        int i = n - 2;

        // Step 1: Find first decreasing from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If such an index was found, find next greater and swap
        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        
        int start = i + 1, end = n - 1;
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
        printArray(nums);
    }
int main(){
    vector<int> nums = {1,3,4,2,5};
    nextPermutation(nums);
}