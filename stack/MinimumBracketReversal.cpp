#include<iostream>
using namespace std;
#include<stack>
#include<string>
int main()
{
    string expr="{{{}";
    stack<char> s;
    int len = expr.length();

    if (len % 2)
        return -1;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '}' && !s.empty()) {
            if (s.top() == '{')
                s.pop();
            else
                s.push(expr[i]);
        }
        else
            s.push(expr[i]);
    }
    int red_len = s.size();
    int n = 0;
    while (!s.empty() && s.top() == '{') {
        s.pop();
        n++;
    }
    int x=red_len / 2 + n % 2;
    cout<<x;

}
