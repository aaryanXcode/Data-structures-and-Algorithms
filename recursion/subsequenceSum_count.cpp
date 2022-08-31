#include<bits/stdc++.h>
using namespace std;
int subsequenceSumK(int index, vector<int> &v,int a[],int n,int s,int sum)
{
    if(index==n)
    {
        if(s==sum)
        {
            return 1;
        }
        else return 0;

    }
    sum+=a[index];
    int l=subsequenceSumK(index+1,v,a,n,s,sum);

    sum-=a[index];
    int r=subsequenceSumK(index+1,v,a,n,s,sum);

    return l+r;;
}
int main()
{
    int a[5]={1,2,3,4,5};
    int n=5;
    int s=5;
    vector<int> v;
    cout<<subsequenceSumK(0,v,a,n,s,0);
}
