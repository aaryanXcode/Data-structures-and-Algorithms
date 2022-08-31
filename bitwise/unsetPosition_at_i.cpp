#include<iostream>
using namespace std;
int main()
{
    int m=10;
    int i=4;
    cout<<(m&(~(1<<i)))<<endl;
}
