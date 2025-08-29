#include<bits/stdc++.h>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> res;
    int currRow = 0, currCol = 0;
    bool goingUp = true;
    bool goingDown = false;

    while(res.size() < n * m) {
        // going up
        while(goingUp && res.size() < n * m) { 
            res.push_back(mat[currRow][currCol]);
            currRow--;
            currCol++;

            if(currRow < 0 || currCol >= m) {
                goingDown = true;
                goingUp = false;
                if(currCol >= m) currRow += 2; 
                else currRow = 0; 
                currCol = min(currCol, m - 1);
            }
        }

        // going down
        while(goingDown && res.size() < n * m) { 
            res.push_back(mat[currRow][currCol]);
            currRow++;
            currCol--;

            if(currCol < 0 || currRow >= n) {
                goingDown = false;
                goingUp = true;
                if(currRow >= n) currCol += 2; 
                else currCol = 0; 
                currRow = min(currRow, n - 1); 
            }
        }
    }
    return res;
}
int main(){
    vector<vector<int>> res = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> ans = findDiagonalOrder(res);
    for(auto x: ans){
        cout<<x<<",";
    }
    return 0;
}