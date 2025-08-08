#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<char>>& word,int n,int m,int i,int j,vector<vector<bool>>&  visited,int idx,const string& searchstr){
    if(i<0 || j<0 ||i>=n || j>=m || visited[i][j] ||  word[i][j] != searchstr[idx]) return false;


    if(idx==searchstr.size()-1) return true;
    visited[i][j] = true;
    bool found = dfs(word,n,m,i+1,j,visited,idx+1,searchstr) 
    ||dfs(word,n,m,i-1,j,visited,idx+1,searchstr) 
    || dfs(word,n,m,i,j+1,visited,idx+1,searchstr) 
    || dfs(word,n,m,i,j-1,visited,idx+1,searchstr);
    visited[i][j] = false;
    return found;
}

int main(){
    vector<vector<char>> word = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string searchstr = "ABCCED";
    int n = word.size();
    int m = word[0].size();
    cout<<"row:"<<n<<" col:"<<m<<endl;
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    bool found = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            if (dfs(word, n, m, i, j, visited, 0, searchstr)) {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    cout << (found ? "Found" : "Not Found") << endl;
    return 0;
}