#include<bits/stdc++.h>
using namespace std;


int minimumArea(vector<vector<int>>& grid) {
    
    int r = grid.size();
    int c = grid[0].size();
    int minRow = r, maxRow = -1;
    int minCol = c, maxCol = -1;
    for(int i = 0 ; i<r; i++){
        for(int j = 0; j<c; j++){
            if(grid[i][j]==1){
                minRow = min(minRow,i);
                maxRow = max(maxRow,i);
                minCol = min(minCol,j);
                maxCol = max(maxCol,j);
            }
        }
    }
    if(maxRow == -1) return 0; 
    int length = maxRow-minRow +1;
    int breadth = maxCol - minCol +1;
    int area = length* breadth;
    return area;
    
}
int main(){
    vector<vector<int>> num = {{0,1,0},{1,0,1}};
    cout<<minimumArea(num)<<endl;
    return 0;
}