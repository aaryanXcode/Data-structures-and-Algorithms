#include <iostream>
#include<vector>
using namespace std;

int main()
{
    string t="abcabaabcababaacdabbabaa";
    string p="abaa";
    int n=t.length();
    int m=p.length();
    cout<<"n="<<n<<endl;
    cout<<"m="<<m<<endl;
    vector<pair<char,int>> v(m);
    for(int i=0;i<m;i++)
    {
        v[i].first=p[i];
        v[i].second=0;
    }
    for(int i=0;i<v.size();i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i].first==v[j].first)
            {
                v[j].second++;
            }
        }
    }

    for(auto k:v)
    {
        cout<<k.first<<" "<<k.second<<endl;
    }
    int i = 0;
    int j = 0;
    while ((n- i) >= (m - j))
    {
        if (p[j] == t[i])
        {
            j++;
            i++;
        }

        if (j == m)
        {
            printf("Found pattern at index %d ", i - j);
            j = v[j].second;
        }
        else if (i < n && p[j] != t[i])
        {
            if (j != 0)
                j = v[j].second;
            else
                i = i + 1;
        }
    }
    return 0;
}

