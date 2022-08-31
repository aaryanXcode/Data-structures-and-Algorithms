#include <iostream>
#include<vector>
using namespace std;

int version(string &v1,string &v2)
{

    int i=0;
    int j=0;
    int n1=0;
    int n2=0;
    while(i<v1.length()|| j<v2.length())
    {
        while(i<v1.length() && v1[i]!='.')
        {
            n1=n1*10+(v1[i]-'0');
            i++;
        }
        while(j<v2.length() && v2[i]!='.')
        {
            n2=n2*10+(v2[i]-'0');
            j++;
        }
        if(n1<n2)
        {
            return -1;
        }
        else if(n1>n2)
        {
            return 1;
        }
        i++;
        j++;
    }
    return 0;
}
int main()
{
    string v1="1.0001";
    string v2="1.01";
    cout<<version(v1,v2);
}
