#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<string>>& word,int n,int m,int i,int j,vector<vector<bool>>&  visited){
    if(i<0 || j<0 || i>=n ||j>=m || visited[i][j]){
        return ;
    } 

    visited[i][j] = true;
    cout<<word[i][j]<<",";
    dfs(word,n,m,i+1,j,visited); //down
    dfs(word,n,m,i-1,j,visited); //up
    dfs(word,n,m,i,j+1,visited); //right
    dfs(word,n,m,i,j-1,visited); //left
}

int main(){
    vector<vector<string>> word = {
        {"A","B","C","E"},
        {"S","F","C","S"},
        {"A","D","E","E"}
    };

    int n = word.size();
    int m = word[0].size();
    cout<<"row:"<<n<<" col:"<<m<<endl;
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    dfs(word,n,m,0,0,visited);
    return 0;

}