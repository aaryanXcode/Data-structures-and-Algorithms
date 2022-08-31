#include<iostream>
using namespace std;
int main()
{
    int a=10;
    int i=4;
    cout<<(a|(1<<i))<<endl;
    //formula for set i th position to 1 M|1<<i   where i is the position to set 1 and M is the original number
    //let say m=10;
    //binary of 10=     0 0 0 0 1 0 1 0  =10
    //1 left shift 5=   0 0 0 1 0 0 0 0  =16
     //                 ________________
    // now take | OR =  0 0 0 1 1 0 1 0  =26
}
