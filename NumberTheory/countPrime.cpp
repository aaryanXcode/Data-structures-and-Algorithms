#include<iostream>
using namespace std;
bool checkPrime(int n)
{
    int countFactors=0;
    for(int j=1;j*j<=n;j++)
    {
        if((n%j)==0)
        {
            if((j*j)==n)
            {
                countFactors+=1;
            }
            else
            {
                countFactors+=2;
            }
        }
    }
    if(countFactors==2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkPrime2(int n)
{
    if(n<=1)
    {
        return false;
    }
    int countFactors=0;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            countFactors++;
        }
    }
    if(countFactors==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++)
    {
        if(checkPrime2(i))
        {
            count++;
        }
    }
    cout<<count<<endl;
}
