#include<bits/stdc++.h>
using namespace std;

int aggressiveCows(vector<int> &nums,int cows){
    int low = 1;
    int n = nums.size();
    int high = nums[n-1]-nums[0];
    int maxStall = high;
    int maxDist = 1;  //min distance would be 1 we have to maximize it
    while(low<=high){
        int mid = low+(high-low)/2;

        //first cow already at first index
        int cowCanFit = 1;
        int lastStall =nums[0];
        for(int i =1;i<n;i++){
            if(nums[i]-lastStall>=mid){
                cowCanFit++;
                lastStall = nums[i];
            }
        }
        if(cowCanFit>=cows){
            maxDist = mid;
            low = mid+1;
        }else {
            high = mid-1;
        }
    }
    return maxDist;
}
    
    

// int aggressiveCows(vector<int> &nums,int cows){
//     int low = 1;
//     int n = nums.size();
//     int high = nums[n-1]-nums[0];
//     int maxStall = high;
//     int maxDist = 1;  //min distance would be 1 we have to maximize it
//     while(low<=high){
//         int mid = low+(high-low)/2;

//         //first cow already at first index
//         int cowCanFit = 1;
//         int lastStall =nums[0];
//         for(int i =1;i<n;i++){
//             if(nums[i]>=mid && nums[i]-lastStall>=mid){
//                 cowCanFit++;
//                 lastStall = nums[i];
//             }
//         }
//         if(cowCanFit==cows){
//             maxDist = mid;
//         }else if(cowCanFit<=cows){
//             high = mid-1;
//         }else{
//             low = mid+1;
//         }
//     }
//     return maxDist;
// }
int main(){
    vector<int> nums = {0,3,4,7,9,10};
    int cows = 4;
    int maxDistance = aggressiveCows(nums,cows);
    cout<<maxDistance<<endl;
}