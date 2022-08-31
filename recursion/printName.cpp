#include<bits/stdc++.h>
using namespace std;
void printName(int i,int n)
{
    if(i==n)
        return ;
    cout<<"Aryan"<<endl;
    printName(i+1,n);

}

int main()
{
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    printName(0,n);
}
