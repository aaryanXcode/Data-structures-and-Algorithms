#include <bits/stdc++.h>
using namespace std;

int row, col;
vector<vector<int>> dp;

//recursion memoization
int paths(vector<vector<int>>& grid, int i, int j){
    if(i >=row || j >= col) return 0;
    if(grid[i][j] == 1) return 0;
    if(i == row-1 && j == col-1) return 1;

    if(dp[i][j]!=-1) return dp[i][j];
    int currentPath = 0;

    currentPath += paths(grid, i+1, j);
    currentPath += paths(grid, i, j+1);
    dp[i][j] = currentPath;
    return dp[i][j];
}

//tabular form
int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
    row = obstacleGrid.size();
    col = obstacleGrid[0].size();
    dp.assign(row+1, vector<int> (col+1, -1));
    dp[0][0] = 1;
    for(int i = 0; i<row ; i++){
        for(int j = 0; j<col; j++){
            if(obstacleGrid[i][j]==1) {
                dp[i][j] = 0; 
                continue;
            }
            if (i == 0 && j == 0) continue;
            long long fromUp   = (i > 0) ? dp[i-1][j] : 0;
            long long fromLeft = (j > 0) ? dp[i][j-1] : 0;
            dp[i][j] = fromUp + fromLeft;
        }
    }
    return (int)dp[row-1][col-1];
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    row = obstacleGrid.size();
    col = obstacleGrid[0].size();
    dp.assign(row+1, vector<int> (col+1, -1));
    return paths(obstacleGrid, 0, 0);
}

int main(){
    vector<vector<int>> grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<uniquePathsWithObstacles(grid)<<endl;
}