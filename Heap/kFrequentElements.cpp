#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    //v.push_back();
    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++)
    {
        m[v[i]]++;
    }
    vector<pair<int,int>> ans;
    for(auto x:m)
    {
        ans.push_back({x.second,x.first});
    }
    cout<<"printing ans"<<endl;
    for(auto &b:ans)
    {
        cout<<b.first<<" "<<b.second<<endl;
    }
    sort(ans.begin(),ans.end());

    cout<<"printing after sorting ans"<<endl;
    for(auto &b:ans)
    {
        cout<<b.first<<" "<<b.second<<endl;
    }
    reverse(ans.begin(),ans.end());
    cout<<"printing after reverse ans"<<endl;
    for(auto &b:ans)
    {
        cout<<b.first<<" "<<b.second<<endl;
    }
}
