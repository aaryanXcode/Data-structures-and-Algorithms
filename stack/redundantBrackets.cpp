#include<iostream>
using namespace std;
#include<stack>
#include<string>
int main()
{
    stack<char> s;
    int count=0;
    string str="(a+(b-c)/d)";
    bool flag=false;

    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='+' || str[i]=='-' ||str[i]=='*' ||str[i]=='/')
        {
            s.push(str[i]);
        }
        else if(str[i]=='(')
        {
            s.push(str[i]);
        }
        else if(str[i]==')')
        {
            if(s.top()=='(')
            {
                flag=true;
            }
            while(s.top()=='+' || s.top()=='-' ||s.top()=='*' ||s.top()=='/')
            {
                s.pop();
            }
            s.pop();
        }
    }
    cout<<flag;

}
