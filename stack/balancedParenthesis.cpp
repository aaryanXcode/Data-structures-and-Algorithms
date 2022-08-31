#include<iostream>
using namespace std;

#include<stack>
#include<string>

int main()
{

    stack<char> s;
    string a="";
    cout<<"pushing into stack\n";
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='(' || a[i]=='[' ||a[i]=='{'){
            s.push(a[i]);
           }

    }
    cout<<"checking and poping out of stack\n";
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==')' && s.top()=='(' || a[i]==']' && s.top()=='[' ||a[i]=='}' && s.top()=='{')
        {
            s.pop();
        }

    }
    if(s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
/*
stack<char> temp;
    string expr="[a+[ b*(c * d)]";

    for(int i=0;i<expr.length();i++)
        {
            if(temp.empty())
            {
                temp.push(expr[i]);
            }
            else if((temp.top()=='('&& expr[i]==')')  ||  (temp.top()=='{' && expr[i]=='}')  ||  (temp.top()=='[' && expr[i]==']'))
            {
                temp.pop();
            }
            else
            {
                temp.push(expr[i]);
            }
        }
        if(temp.empty())
        {
            return true;
        }
        return false;
*/

}
