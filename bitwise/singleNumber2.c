#include<iostream>
using namespace std;
int singleNumber(vector<int>& nums)
{
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]++];
        }
        for(auto k:m)
        {
            cout<<k.first<<" "<<k.second<<endl;
        }

}
int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    singleNumber(v);

}
