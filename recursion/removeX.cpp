#include<iostream>
using namespace std;
void removeX(char input[], int start,int n)
{
    if(input[start] == '\0')
    {
        return;
    }
    removeX(input, start+1,n);
    if(input[start] == 'x')
    {

        int i;
        for(i = start+1; i < len; i++)
        {
            input[i-1] = input[i];
        }
        input[i-1] = '\0';
    }
}
int main()
{
    string s="axabx";
    int n=s.size();
    removeX(s,0,n);
    for(int i=0i<n;i++)
    {
        cout<<s[i];
    }
}
