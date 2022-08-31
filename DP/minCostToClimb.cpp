#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minCost(int n,int *ans)
{
    //using memoization
    if(n==1)
    {
        return 0;
    }
    int y=INT_MAX,z=INT_MAX,x;

    if(ans[n]!=-1)
    {
        return ans[n];
    }
    x=minCost(n-1,ans);
    if(n%2==0)
    {
        y=minCost(n/2,ans);
    }
    if(n%3==0)
    {
        z=minCost(n/3,ans);
    }
    int output=1+min(x,min(y,z));
    ans[n]=output;
    return ans[n];
}

int minCost(int n)
{
    int *ans=new int[n+1];

    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }
    return minCost(n,ans);

}

/*
int minCost(int n,int *ans)
{   //using bruteforce recursion
    if(n==1)
    {
        return 0;
    }
    int y=INT_MAX,z=INT_MAX,x;


    x=minCost(n-1);
    if(n%2==0)
    {
        y=minCost(n/2);
    }
    if(n%3==0)
    {
        z=minCost(n/3);
    }
    return 1+min(x,min(y,z));
}
*/

int main()
{
    int n;
    cin>>n;
    cout<<minCost(n);
}
