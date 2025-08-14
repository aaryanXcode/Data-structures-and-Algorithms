#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int row, col;

//tabular
int paths(int i, int j, vector<vector<int>>& grid){
    dp[i][j] = grid[i][j];
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            if (i == 0 && j == 0) continue;
            if(i>0 && j>0)
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            else if (i > 0) { 
                dp[i][j] = grid[i][j] + dp[i-1][j];
            }
            else if (j > 0) { 
                dp[i][j] = grid[i][j] + dp[i][j-1];
            }
        }
    }
    return dp[row-1][col-1];
}

//recursion + memoization
int paths(int i, int j, vector<vector<int>>& grid){
    if(i>=row || j>=col) return INT_MAX;
    if(i == row-1 && j == col -1) return grid[i][j];
    
    int downSum = paths(i+1, j, grid);
    int rightSum = paths(i, j+1, grid);

    if(downSum!=INT_MAX)
        downSum += grid[i][j];
    if(rightSum!=INT_MAX)
        rightSum += grid[i][j];

    return min(downSum,rightSum);
}
int minPathSum(vector<vector<int>>& grid) {
    dp.assign(row+1, vector<int> (col+1, -1));
    return paths(0, 0, grid);
}

int main(){
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    row = grid.size();
    col = grid[0].size();
    cout<<minPathSum(grid)<<endl;
}