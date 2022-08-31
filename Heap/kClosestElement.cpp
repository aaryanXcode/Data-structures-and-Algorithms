
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    int k=4;
    int x=3;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>  p;
    for(int i=0;i<nums.size();i++)
    {
        p.push({nums[i],abs(nums[i]-x)});
    }


    vector<pair<int,int>> ans;
    while(!p.empty())
    {
        auto a = p.top();
        p.pop();
        ans.push_back({a.second , a.first});
    }

    for(auto &b:ans)
    {
        cout<<b.first<<" "<<b.second<<endl;
    }
    sort(ans.begin(),ans.end());
    for(auto &b:ans)
    {
        cout<<b.first<<" "<<b.second<<endl;
    }
    vector<int> v;
    for(int i=0;i<k;i++)
    {
        v.push_back(ans[i].second);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<",";
    }
}

