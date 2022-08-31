#include<iostream>
using namespace std;
int countZero(int n)
{
    if(n <=9)
    {
        if(n==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int r = n % 10;

    if(r == 0)
    {
        return 1 + countZero(n/10);
    }
    return countZero(n/10);

}
int main()
{
    int n;
    cin>>n;
    cout<<countZero(n);
}
