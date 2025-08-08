#include<bits/stdc++.h>
using namespace std;
bool isValidPosition(int row, int col, vector<vector<int>>& board, int n) {
    // Check column ↑
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal ↖
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal ↗
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}


void nqueen(int n,vector<vector<int>>& board,int row,vector<vector<vector<int>>>& solutions){
    if(row==n){
        solutions.push_back(board);
        return ;
    }
    for(int col = 0;col<n;col++){
        if(isValidPosition(row,col,board,n)){
            board[row][col] = 1;
            nqueen(n,board,row+1,solutions);
            board[row][col] = 0;
        }
    }
    
}

int main(){
    int n = 4;
    vector<vector<vector<int>>> solutions;
    vector<vector<int>> board(n, vector<int>(n, 0));
    nqueen(n,board,0,solutions);

    for(auto x:solutions){
        for(auto y : x){
            for(auto z:y){
                cout<<z<<",";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}