#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int getmaxPathSum(int m,int n,vector<vector<int>>&mat)
{
    vector<vector<int>> dp(m,vector<int>(m,0));
    for(int j=0;j<m;j++)
    {
        dp[0][j]=mat[0][j];
    }
    cout<<"checking value of dp"<<endl;

    for(int i=1;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u=mat[i][j]+dp[i-1][j];
            cout<<"value of "<<i<<" value of j "<<j<<" value of u "<<u<<endl;
            int ld=mat[i][j];
            if(j-1>=0)
            {
                ld+=dp[i-1][j-1];
            }
            else
            {
                ld+=-1e8;
            }
            cout<<"value of "<<i<<" value of j "<<j<<" value of ld "<<ld<<endl;
            int rd=mat[i][j];
            if(j+1<m)
            {
                rd+=-1e8;
            }
            cout<<"value of "<<i<<" value of j "<<j<<" value of rd "<<rd<<endl;
            dp[i][j]=max(u,max(ld,rd));
        }
        for(int p=0;p<m;p++)
        {
            for(int q=0;q<n;q++)
            {
                cout<<dp[p][q]<<" ";
            }
            cout<<endl;
        }

    }
}
int main()
{

    int m=3;
    int n=3;
    vector<vector<int>> v
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout<<getmaxPathSum(m,n,v);

}
