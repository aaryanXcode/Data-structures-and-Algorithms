#include<iostream>
using namespace std;
int digitSum(int n)
{
//    if(n==0)
//    {
//        return 0;
//    }
    if(n<=9)
    {
        return n;
    }
    int a=n%10;
    return a+digitSum(n/10);
}
int main()
{
    int n;
    cin>>n;
    cout<<digitSum(n);
}
