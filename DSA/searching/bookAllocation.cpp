#include<bits/stdc++.h>
using namespace std;

int bookAllocation(vector<int> &nums,int students){
    int n = nums.size();
    if(students>n) return -1;
    int low = *max_element(nums.begin(), nums.end());;
    int high = accumulate(nums.begin(),nums.end(),0);
    int maxBookAllocation = high;
    while(low<=high){
        int mid = low+(high-low)/2;
        int resPages = 0;
        int bookAllocatedToStudent = 1; // start with one student

        for (int i = 0; i < n; i++) {
            if (resPages + nums[i] > mid) {
                bookAllocatedToStudent++;    // new student
                resPages = nums[i];          // start counting from current book
            } else {
                resPages += nums[i];         // accumulate pages for current student
            }
        }

        if(bookAllocatedToStudent>students){
            low = mid+1;
        }else{
            maxBookAllocation = mid;
            high = mid-1;
        }
    }
    return maxBookAllocation;
}
int main(){
    vector<int> arr = {12, 34, 67, 90};
    int maxBookAllocation = bookAllocation(arr,2);
    cout<<maxBookAllocation<<endl;
}