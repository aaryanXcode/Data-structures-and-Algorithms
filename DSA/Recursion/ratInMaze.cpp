#include<bits/stdc++.h>
using namespace std;

    void dfs(int i,int j,vector<vector<int>>& maze,vector<string>& paths,string currpath,vector<vector<bool>>& visited,int n,int m){
        if(i<0 || j<0 ||i>=n || j>=m ||visited[i][j] || maze[i][j]==0) return ;

        if(i==n-1 && j== m-1) {
            paths.push_back(currpath);
            return ;
        }
        
        visited[i][j] = true;

        currpath +="D";
        dfs(i+1,j,maze,paths,currpath,visited,n,m);
        currpath.pop_back();

        currpath +="U";
        dfs(i-1,j,maze,paths,currpath,visited,n,m);
        currpath.pop_back();

        currpath +="R";
        dfs(i,j+1,maze,paths,currpath,visited,n,m);
        currpath.pop_back();

        currpath +="L";
        dfs(i,j-1,maze,paths,currpath,visited,n,m);
        currpath.pop_back();

        visited[i][j] = false;
    }
    int main(){
        vector<vector<int>> maze = {{1, 0, 0, 0},
            {1, 1, 0, 1}, 
            {1, 1, 0, 0},
            {0, 1, 1, 1}};
            int n = maze.size();
            int m = maze[0].size();
            string currpath = "";
            vector<string> paths;
            vector<vector<bool>> visited(n,vector<bool>(m,false));
            dfs(0,0,maze,paths,currpath,visited,n,m);
            for(auto x:paths){
                cout<<x<<endl;
            }
            return 0;
    }