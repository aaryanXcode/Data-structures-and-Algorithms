#include<bits/stdc++.h>
using namespace std;
int kokoBinarySearch(vector<int> &nums,int n,int h){
    //sort(nums.begin(),nums.end()); no need to sort the array because we are finding ans in running space which is already sorted 1<=maxbanana
    int maxBanana = *max_element(nums.begin(),nums.end());
    int low = 1;
    int high = maxBanana;
    int mink = INT_MAX;

    while(low<=high){
        int mid = low+(high-low)/2;
        
        int hour = 0;
        for (int j = 0; j < n; j++) {
            // simulate ceil(nums[j] / k)
            hour += (nums[j] + mid- 1) / mid;
        }
        if (hour <= h) {
            mink = mid;  // since we go from 1 upward, first match is minimum
            high = mid-1;     // break because further k will only be larger
        }else{
            low = mid+1;
        }
    }
    return mink;

}
int kokoEatBanana(vector<int> &nums,int n,int h){

    int mink = INT_MAX;
    int maxBanana = *max_element(nums.begin(), nums.end());
    for (int k = 1; k <= maxBanana; k++) {
        int hour = 0;

        for (int j = 0; j < n; j++) {
            // simulate ceil(nums[j] / k)
            hour += (nums[j] + k - 1) / k;
        }

        if (hour <= h) {
            mink = k;  // since we go from 1 upward, first match is minimum
            break;     // break because further k will only be larger
        }
    }
    return mink;
}


int main(){
    vector<int> nums = {3,6,7,11};
    int n = 4;
    int h = 8;
    int k = kokoEatBanana(nums,n,h);
    cout<<"eat k banana in an hour:"<<k<<endl;
}