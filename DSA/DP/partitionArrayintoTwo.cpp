#include<bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        vector<vector<char>> dp(n+1, vector<char>(totalSum+1, false));
        
        // sum=0 is always possible
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // subset sum filling
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= totalSum; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        // find minimal difference
        int minm = INT_MAX;
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[n][s1]) {
                int s2 = totalSum - s1;
                minm = min(minm, abs(s2 - s1));
            }
        }
        return minm;
    }

int main(){
    vector<int> nums = {2,-1,0,4,-2,-9};
    cout<<minimumDifference(nums);
    return 0;
}
