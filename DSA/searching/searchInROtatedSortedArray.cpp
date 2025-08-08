#include<bits/stdc++.h>
using namespace std;
//searching in one go without pivot
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the target
        if (nums[mid] == target)
            return mid;

        // Check which half is sorted
        if (nums[low] <= nums[mid]) {
            // Left half is sorted
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1; // target in left
            } else {
                low = mid + 1; // target in right
            }
        } else {
            // Right half is sorted
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1; // target in right
            } else {
                high = mid - 1; // target in left
            }
        }
    }

    return -1; // not found
}




int pivot(vector<int>&nums){
        
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // If mid element is greater than high, minimum is in right half
        if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            // Minimum is in left half (including mid)
            high = mid;
        }
    }

    return low;
}

int searchInRotatedArray(vector<int> &nums,int target,int low,int high){
    while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    return -1;
}
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int j =n-1;
    
    int idx = pivot(nums);
    int foundAt1 = searchInRotatedArray(nums,target,idx,n-1);
    int foundAt2 = searchInRotatedArray(nums,target,0,idx-1);
    return max(foundAt1,foundAt2);
}
int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    int idx = search(nums,0);
    cout<<"found at index:"<<idx<<endl;
}