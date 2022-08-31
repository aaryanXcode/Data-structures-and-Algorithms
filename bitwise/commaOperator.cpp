#include<iostream>
using namespace std;
int main()
{
    int a=10,b;
    b=(a++,++a);
    cout<<a<<" "<<b<<endl;
    b=a++,++a;
    cout<<a<<" "<<b<<endl;

}
