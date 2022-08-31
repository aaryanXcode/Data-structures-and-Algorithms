#include<iostream>
#include<stack>
using namespace std;
void sortInsert(int element,stack<int>&s)
{
    if(s.empty()|| element>s.top() )
    {
        s.push(element);

    }
    else
    {
        int top_element=s.top();
        s.pop();
        sortInsert(top_element,s);
        s.push(top_element);
    }
}
void sortStack(stack<int>&s)
{
    if(s.empty())
    {
        return ;
    }
    int a=s.top();
    sortStack(s);
    sortInsert(a,s);

}
int main()
{
    stack<int> s;
    s.push(8);
    s.push(9);
    s.push(-1);
    s.push(4);
    s.push(3);
    sortStack(s);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}
