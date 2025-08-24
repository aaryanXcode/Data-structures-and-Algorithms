#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums = {1,3,5,4,7};
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];  // reset count
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j]; // add more ways
                }
            }
        }
    }

    int maxVal = *max_element(dp.begin(), dp.end());
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxVal) {
            result += count[i];
        }
    }
    cout<<result;


    return 0;
}