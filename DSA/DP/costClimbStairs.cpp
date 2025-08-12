vector<int> dp;

//memoization
int minCostHelper(vector<int>& cost, int startFrom, int n){
    
    if(startFrom>=n){
        return 0;
    }
    if(dp[startFrom]!=-1)
        return dp[startFrom];
    int cost1 = minCostHelper(cost,startFrom+1, n);
    int cost2 = minCostHelper(cost,startFrom+2, n);
    dp[startFrom] = cost[startFrom] + min(cost1,cost2);
    return dp[startFrom];
}

//tabular
int tabular(vector<int>& cost, int n){
    for(int i = 2; i<n;i++){
        dp[i] = cost[i] +min(dp[i-1],dp[i-2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}

int minCostClimbingStairs1(vector<int>& cost) {
    int n = cost.size();
    dp.assign(n+1,0);
    
    int startFromZero = tabular(cost,0,n);
    int startFromOne = tabular(cost,1,n);
    return min(startFromZero, startFromOne);
}

int minCostClimbingStairs2(vector<int>& cost){
    int n = cost.size();
    dp.assign(n+1,0);
    dp[0] = cost[0]; //if start from 0
    dp[1] = cost[1]; //if start from 1
    return tabular(cost, n);
}