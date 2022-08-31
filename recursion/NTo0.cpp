#include<bits/stdc++.h>
using namespace std;
void printN_to_0(int i,int n)
{
    if(i<0)
        return ;
    cout<<i<<endl;
    printN_to_0(i-1,n);
}
int main()
{
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    printN_to_0(n,n);
}

