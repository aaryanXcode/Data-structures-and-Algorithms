#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int gcdOf(int a, int b) {
    return b == 0 ? a : gcdOf(b, a % b);
}

vector<vector<int>> dp;

int findWays(vector<vector<int>>& mat, int row, int currGcd) {
    if (row == mat.size()) {
        return (currGcd == 1);
    }

    if (dp[row][currGcd] != -1)
        return dp[row][currGcd];

    long long ways = 0;
    for (int num : mat[row]) {
        int newGcd = (currGcd == 0) ? num : gcdOf(currGcd, num);
        ways = (ways + findWays(mat, row + 1, newGcd)) % MOD;
    }

    return dp[row][currGcd] = ways;
}

int countWays(vector<vector<int>>& mat) {
    int n = mat.size();
    int maxVal = 0;
    for (auto& row : mat)
        for (int num : row)
            maxVal = max(maxVal, num);

    dp.assign(n + 1, vector<int>(maxVal + 1, -1));

    return findWays(mat, 0, 0);
}

int main() {
    vector<vector<int>> mat = {{1, 2}, {3, 4}};
    cout << countWays(mat) << endl;
    return 0;
}
