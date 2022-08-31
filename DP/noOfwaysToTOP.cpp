#include<iostream>
using namespace std;

//using dp
//space optimization
int noofways3(int n)
{
    int prev1=1;
    int prev2=1;
    int prev3=0;
    int current=-1;
    for(int i=2;i<=n;i++)
    {
        current=prev1+prev2+prev3;
        prev3=prev2;
        prev2=prev1;
        prev1=current;
    }
    return current;

}


//topdown
//using memoization
int noofways2_help(int n,int *ans)
{
    if(n==0)
    {
        return 1;
    }
    if(n<1)
    {
        return 0;
    }
    if(ans[n]!=-1)
    {
        return ans[n];
    }
    else
    {
        int x=noofways2_help(n-1,ans);
        int y=noofways2_help(n-2,ans);
        int z=noofways2_help(n-3,ans);
        ans[n]=x+y+z;
    }

    return ans[n];
}

int noofways2(int n)
{
    int *ans=new int[n+1];
    for(int i=0;i<=n;i++)
    {
        ans[i]=-1;
    }
    return noofways2_help(n,ans);
}


int noOfways(int n)
{

    if(n==0)
    {
        return 1;
    }
    if(n<1)
    {
        return 0;
    }
    int x=noOfways(n-1);
    int y=noOfways(n-2);
    int z=noOfways(n-3);
    return x+y+z;

}
int main()
{
    int n;
    cin>>n;
    cout<<noofways3(n);
}
