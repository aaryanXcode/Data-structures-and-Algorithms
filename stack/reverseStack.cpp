#include<iostream>
using namespace std;
#include<stack>

int main()
{
    stack<int> s1,s2;
    int temp;
    s1.push(10);
    s1.push(20);

    int len=s1.size();
   // cout<<len<<"\n";
    int count=0;

    cout<<"\n";
    for(int i=0;i<len;i++)
    {

        temp=s1.top();
        s1.pop();
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        if(s1.empty())
        {
            //cout<<temp<<"check"<<endl;
            s1.push(temp);
            //cout<<s1.top()<<endl;
        }

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        count++;
    }
    cout<<"after reverse"<<endl;
    while(!s1.empty())
    {
        cout<<s1.top()<<endl;
        s1.pop();
    }



}
