#include<bits/stdc++.h>
using namespace std;
void reverseArray(int a[],int i,int n)
{
    if(i>=n/2)
    {
        swap(a[i],a[n-i-1]);
        return ;
    }
    reverseArray(a,i+1,n);
}
int main()
{
    int a[5]={1,2,3,4,5};
    reverseArray(a,0,5);
    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<endl;
    }
}

