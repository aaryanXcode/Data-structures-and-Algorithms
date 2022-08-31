
#include<iostream>
using namespace std;
int main()
{
    int a[5]={2,1,4,3}; //

    int n=5;   //
    int sum=n*(n+1)/2;
    for(int i=0;i<n;i++)
    {
        sum=sum-a[i];
    }
    cout<<"missing number is="<<sum<<endl;
}
