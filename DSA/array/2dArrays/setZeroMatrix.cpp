#include<bits/stdc++.h>
using namespace std;


void setZeroes(vector<vector<int>>& v) {
        unordered_set<int> zeroWalaRow;
        unordered_set<int> zeroWalaCol;
        for(int i =0;i<v.size();i++){
            for(int j = 0;j<v[0].size();j++){
                if(v[i][j]==0){
                    zeroWalaRow.insert(i);
                    zeroWalaCol.insert(j);
                }
            }
        } 
        for(int i =0;i<v.size();i++){
            if(zeroWalaRow.count(i)){
                for(int j=0;j<v[0].size();j++){
                        v[i][j] = 0;
                }
            }
        }

        for(int j = 0;j<v[0].size();j++){
            if(zeroWalaCol.count(j)){
                for(int i=0;i<v.size();i++){
                    v[i][j] = 0;
                }
            }
        }
    }

void up(vector<vector<int>> &v,int row , int column){
    for(int k = row; k>=0; k--){
        v[k][column] = 0;
    }
}

void down(vector<vector<int>> &v,int row,int column){
    for(int k = row; k<v.size();k++){
        v[k][column] = 0;
    }
}

void left(vector<vector<int>> &v,int row,int column){
    for(int k =column;k>=0;k--){
        v[row][k] = 0;
    }
}

void right(vector<vector<int>> &v,int row,int column){
    for(int k = column;k<v[0].size();k++){
        v[row][k] = 0;
    }
}



int main(){
    vector<vector<int>> v = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    vector<pair<int, int>> zeroPositions;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            if (v[i][j] == 0) {
                zeroPositions.push_back({i, j});
            }
        }
    }

    for (auto [row, col] : zeroPositions) {
        up(v, row, col);
        down(v, row, col);
        left(v, row, col);
        right(v, row, col);
    }
    printArray(v);
}