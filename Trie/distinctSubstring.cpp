/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{

    string word="aaa";
    set<string> s;

    for (int i = 0; i <= word.length(); i++)
    {
        for (int j = 1; j <= word.length()-i; j++)
        {
            s.insert(word.substr(i,j));
        }
    }
    for(auto &x:s)
    {
        cout<<x<<endl;
    }
}

