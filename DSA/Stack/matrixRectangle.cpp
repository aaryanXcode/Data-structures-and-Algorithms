#include<bits/stdc++.h>
using namespace std;

void rectangle(vector<vector<char>>& rec, int row, int col, int i, int j, int n, int m){
    if(i<=0 || j<=0 || i>=n || j>=m || rec[i][j]=='0') return;
    if(rec[i][j]==1){
        row++,
        column++;
        return ;
    }

    return rectangle(rec,row,column,i+1,j,n,m) && rectangle(rec,row,column,i-1,j,n,m) && rectangle(rec,row,column,i,j+1,n,m) && rectangle(rec,row,column,i,j-1,n,m);
}
int main(){
    vector<vector<char>> rec = {{'1','0','1','0','0'},
                                {'1','0','1','1','1'},
                                {'1','1','1','1','1'},
                                {'1','0','0','1','0'}};
    int row = -1;
    int column = -1;
    int n = rec.size();
    int m = rec[0].size();
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            rectangle(rec,row,column,i,j);
        }
    }
    
}