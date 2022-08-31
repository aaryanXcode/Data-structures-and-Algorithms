#include<iostream>
#include<bits/stdc++.h>
using namespace std;
float geometricSum(int k)
{
    if(k==0)
    {
        return 1;
    }
   float a=geometricSum(k-1);
   return (float)(a+(1/pow(2,k)));

}
int main()
{
    int k;

    cin>>k;
    cout<<geometricSum(k);
}
