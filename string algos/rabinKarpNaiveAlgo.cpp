/*******************************************************************************/
//algorithm from clrs
//  1. n ← length [T]
//  2. m ← length [P]
//  3. for s ← 0 to n -m
//  4. do if P [1.....m] = T [s + 1....s + m]
//  5. then print "Pattern occurs with shift" s
#include <iostream>

using namespace std;

int main()
{
    string t="abcabaabcababaacdabbabaa";
    string p="abaa";
    int n=t.length();
    int m=p.length();
    cout<<"n="<<n<<endl;
    cout<<"m="<<m<<endl;
    for(int s=0;s<=n-m;s++)
    {
        int i;
        for(i=0;i<m;i++)
        {
            if(t[s+i]!=p[i])
            {
                break;
            }
        }
        if(i==m)
        {
            cout<<"pattern found at="<<s<<endl;
        }
    }

    return 0;
}

