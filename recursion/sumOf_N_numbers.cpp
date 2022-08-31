#include<bits/stdc++.h>
using namespace std;
//parameterized
void sum(int i,int sum_n)
{
    if(i<0)
    {
        cout<<sum_n<<endl;
        return ;
    }
    sum(i-1,sum_n+i);


}
//functional on the basis of return value
int sum(int n)
{
    if(n==0)
        return 0;
    return n+sum(n-1);
}

int main()
{
    int n;
    cout<<"enter n"<<endl;
    cin>>n;
    //sum(n,0);
    int totalsum=sum(n);
    cout<<totalsum<<endl;
}

