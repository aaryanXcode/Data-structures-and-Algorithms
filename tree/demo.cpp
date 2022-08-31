
#include <iostream>

using namespace std;

int main()
{
    int x=100;
    int y=100;
    cout<<"m"<<" "<<"x"<<" "<<"y"<<endl;
    for(int m=0;m<3;m++)
    {
        for(int i=0;i<10;x+=100,i++)
        {
            cout<<m<<" "<<x<<" "<<y<<endl;
        }
        cout<<endl;
        x=100;
        y=y+200;
    }
    return 0;
}
