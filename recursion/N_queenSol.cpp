#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j,int n,vector<vector<int>> &chessBoard)
{
    int row=i;
    int column=j;
    while(row>=0)
    {
        if(chessBoard[row][column]==1)
            return false;
        row--;
    }
    row=i;
    column=j;
    while(row>=0 && column<n)
    {
        if(chessBoard[row][column]==1)
            return false;
        row--;
        column++;
    }

    row=i;
    column=j;
    while(row>=0 && column>=0)
    {
        if(chessBoard[row][column]==1)
            return false;
        row--;
        column--;
    }
    return true;
}
void help(int i,int n,vector<vector<int>> &chessBoard,vector<vector<int>>& ans)
{
    if(i==n)
    {
        vector<int> temp;

        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                temp.push_back(chessBoard[j][k]);
            }
        }
        ans.push_back(temp);
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(isSafe(i,j,n,chessBoard))
        {
            chessBoard[i][j]=1;
            help(i+1,n,chessBoard,ans);
            chessBoard[i][j]=0;
        }
    }

}

int solveNqueen(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> chessBoard(n,vector<int>(n,0));
    help(0,n,chessBoard,ans);
    cout<<"ans="<<ans.size();
    cout<<"Ans="<<ans[0].size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j];
        }
        cout<<endl;
    }



}

int main()
{
    int n=4;
    solveNqueen(4);

}
