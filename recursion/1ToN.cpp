#include<bits/stdc++.h>
using namespace std;
void printNo(int i,int n)
{
    if(i==n)
        return ;
    cout<<i<<endl;
    printNo(i+1,n);
}
int main()
{
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    printNo(0,n);
}
