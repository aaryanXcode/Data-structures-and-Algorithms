
#include<bits/stdc++.h>
using namespace std;

//recursion + memoization
int n;
vector<vector<int>> dp;
int count(vector<int>& coins, int amount, int i, int currAmount) {
    if(currAmount > amount) return INT_MAX; 
    if(currAmount == amount) return 0; 

    if(dp[i][currAmount] != -1) return dp[i][currAmount];

    // take the coin at index i
    int take = count(coins, amount, i, currAmount + coins[i]); // took but we didint increase the inidex to reuse the same coin max time to achieve our target
    if(take != INT_MAX) take += 1;

    // skip the coin
    int nottake = count(coins, amount, i+1, currAmount); // if we didnt took the element then their is no point to stay on that and adding to our set

    return dp[i][currAmount] = min(take, nottake);
}


//tabular form    
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<ll>> dp(n+1,vector<ll>(amount+1,INT_MAX));
    for(int i = 0; i<=n; i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i<=n;i++){
        for(int j = 1; j<=amount; j++){
            dp[i][j] = dp[i-1][j];
            if(coins[i-1] <= j && dp[i][j - coins[i-1]] != INT_MAX) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i-1]]);
            }
        }
    }
    return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];

}

int coinChange(vector<int>& coins, int amount) {
    n = coins.size();
    dp.assign(n + 1, vector<int>(amount + 1, -1));
    int ans = count(coins, amount, 0, 0);
    return (ans == INT_MAX) ? -1 : ans;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << coinChange(coins, amount);
}
