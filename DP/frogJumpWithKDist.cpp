
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//using memoization

int frogEnergy2(int n,int *heights,vector<int>&dp,int k)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {

        return dp[n];
    }
    int minJumps=INT_MAX;
    int jumps;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
            jumps=frogEnergy2(n-i,heights,dp,k)+abs(heights[n]-heights[n-i]);
        minJumps=min(jumps,minJumps);
    }
    dp[n]=minJumps;
    return dp[n];
}
int frogJump2(int n,int *heights,int k)
{
    vector<int>dp(n+1,-1);
    return frogEnergy2(n-1,heights,dp,k);
}

//basic and brute force recursion
/*
int frogEnergy(int n,int *heights)
{
    if(n==0)
    {
        return 0;
    }
    int right=INT_MAX;
    int left=frogEnergy(n-1,heights)+abs(heights[n]-heights[n-1]);
    if(n>1)
    {
        right=frogEnergy(n-2,heights)+abs(heights[n]-heights[n-2]);
    }
    return min(left,right);
}
int frogJump(int n,int *heights)
{
    return frogEnergy(n-1,heights);
}
*/
int frogEnergy(int n,int *heights,int k)
{
    if(n==0)
    {
        return 0;
    }
    int minJumps=INT_MAX;
    int jumps;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
            jumps=frogEnergy(n-i,heights,k)+abs(heights[n]-heights[n-i]);
        minJumps=min(jumps,minJumps);
    }
    return minJumps;
}
int frogJump(int n,int *heights,int k)
{
    return frogEnergy(n-1,heights,k);
}
int main()
{
    int heights[6]={30,10,60,10,60,50};
    //cout<<frogJump(6,heights);
    cout<<frogJump2(6,heights,4);
}
