#include<bits/stdc++.h>
using namespace std;
void print(int i,int n)
{
    if(i>n)
        return ;
    print(i+1,n);
    cout<<i<<endl;

}
int main()
{
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    print(1,n);
}

