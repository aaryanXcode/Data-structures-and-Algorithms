// #include<bits/stdc++.h>
// using namespace std;

// void printArray(vector<int>&nums){
//     int n = nums.size();
//     for(int i =0;i<nums.size();i++){
//         cout<<nums[i]<<",";
//     }
//     cout<<endl;
// }
// void rearrangeArray(vector<int>& nums) {
//     int n = nums.size();
//     for(int i = 0; i < n - 1; i++) {
//         // If sign is wrong at even index
//         if(nums[i] < 0 && i % 2 == 0) {
//             int j = i + 1;
//             while(j < n && nums[j] < 0) j++;
//             if(j < n) swap(nums[i], nums[j]);
//         }
//         // If sign is wrong at odd index
//         else if(nums[i] > 0 && i % 2 != 0) {
//             int j = i + 1;
//             while(j < n && nums[j] > 0) j++;
//             if(j < n) swap(nums[i], nums[j]);
//         }
//     }
//     printArray(nums);
// }

// int main(){
//     vector<int> nums = {3,1,-2,-5,2,-4};
//     rearrangeArray(nums);
// }

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int>&nums){
    int n = nums.size();
    for(int i =0;i<nums.size();i++){
        cout<<nums[i]<<",";
    }
    cout<<endl;
}
vector<int> rearrangeArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n,0);
    int posidx =0;
    int negidx = 1;
    for(int i=0;i<n;i++){
        if(nums[i]>0){
            result[posidx]= nums[i];
            posidx+=2;
        }else{
            result[negidx] = nums[i];
            negidx+=2;
        }
    }
    return result;
}

int main(){
    vector<int> nums = {28,-41,22,-8,-37,46,35,-9,18,-6,19,-26,-37,-10,-9,15,14,31};
    vector<int> res = rearrangeArray(nums);
    printArray(res);
}