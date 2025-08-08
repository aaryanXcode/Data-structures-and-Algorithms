#include<bits/stdc++.h>
using namespace std;
int findKthPositive2(vector<int>& arr, int k) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        int missingBefore = arr[i] - (i + 1);
        if (missingBefore >= k) {
            return k + i;
        }
    }

    // If not found in loop, missing number lies beyond last element
    return k + n;
}
int findKthPositive(vector<int>& arr, int k) {
        vector<int> nums(1001,-1);
        int n = arr.size();
        for(int i =0;i<n;i++){
            nums[arr[i]] = arr[i];
        }
        int x =0;
        int ans = -1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==-1){
                x++;
            }
            if(x==k){
                ans =i;
                break;
            }
        }
        return ans;
    }

int main(){
    vector<int> arr ={2,3,4,7,11};
    int k = 5;
    int missingkth = findKthPositive2(arr,k);
    cout<<missingkth<<endl;
}