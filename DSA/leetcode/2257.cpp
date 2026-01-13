#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<int>> blocks(m, vector<int>(n,-1));
    for(auto &g: guards){
        blocks[g[0]][g[1]] = 1;
    }

    for(auto &w: walls){
        blocks[w[0]][w[1]] = 0;
    }
    
    for(auto &g : guards){
        int r = g[0];
        int c = g[1];
        for( auto [dr,dc] : dirs){
            int nr = r+dr;
            int nc = c+dc;
            while (nr>=0 && nr<m && nc >= 0 && nc<n && blocks[nr][nc] != 0 && blocks[nr][nc]!= 1) {
                blocks[nr][nc] = 2; 
                nr += dr;
                nc += dc;
            }
        }
    }

    int unguarded = 0;
    for(auto vec: blocks){
        for(auto ele:vec){
            if(ele==-1) unguarded++;
        }
    }
    return unguarded;
}

int main(){
    vector<vector<int>> guards = {{0,0},{1,1},{2,3}};
    vector<vector<int>> walls = {{0,1},{2,2},{1,4}};
    int m = 4, n = 6;
    cout<<countUnguarded(m, n, guards, walls)<<endl;

}