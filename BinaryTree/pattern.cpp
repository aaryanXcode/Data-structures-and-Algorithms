#include<iostream>
using namespace std;
int main()
{
    int i,k,j,m;
    int n=4;
    for( i=n;i>=1;i--)
    {

        for (m = 0; m < n-i; m++) {
            cout<<" ";
        }
        for( j=i;j>=1;j--)
        {
            cout<<j;
        }
        if(i%2!=0)
        {
            for( k=j+2;k<=i-1;k++)
            {
                cout<<k;
            }
        }
        else
        {
            for( k=j+2;k<=i;k++)
            {
                cout<<k;
            }
        }

        cout<<endl;
    }
}
