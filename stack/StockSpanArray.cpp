#include<iostream>
using namespace std;
int main()
{
    int a[]={100,80,60,70,60,75,85};
    int n=7;
    int count=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j>=0;j--)
        {
            if(a[i]<a[j])
            {
                cout<<count<<endl;
                count=0;
                break;


            }
            count++;
        }
    }
    cout<<count<<endl;

}
