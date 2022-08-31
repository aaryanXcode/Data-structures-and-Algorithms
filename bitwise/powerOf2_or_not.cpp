#include<iostream>
using namespace std;

int main()
{
    int m=47;
    cout<<(m&(~m))<<endl;
    if((m&(~m))==0)
    {
        cout<<"power of 2"<<endl;
    }
    else
        cout<<"not power of 2"<<endl;

    cout<<(m&(m-1))<<endl;
    cout<<(m&(-m))<<endl;
}

//m&(m-1)
//m&(-m)
