#include<iostream>
using namespace std;
int reverseBits(int n)
{
    int rev=0;
    while(n>0)
    {
        rev<<=1;
        if((n&1)==1)
            rev^=1;
        n>>=1;
    }
    return rev;
}
int main()
{

    int reversed=reverseBits(43261596);
    cout<<reversed<<endl;
}
