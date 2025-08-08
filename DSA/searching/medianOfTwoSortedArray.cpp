#include<bits/stdc++.h>
using namespace std;
//try to find using binary search


//brute force
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> nums(n + m);
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (nums1[i] < nums2[j]) {
            nums[k++] = nums1[i++];
        } else {
            nums[k++] = nums2[j++];
        }
    }

    while (i < n) nums[k++] = nums1[i++];
    while (j < m) nums[k++] = nums2[j++];

    int total = n + m;
    if (total % 2 == 1) {
        return nums[total / 2];
    } else {
        return (nums[total / 2 - 1] + nums[total / 2]) / 2.0;
    }        
}

int main(){
    vector<int> num1 ={1,3};
    vector<int> num2 ={2};
    int median = findMedianSortedArrays(num1,num2);
    cout<<median<<endl;
}