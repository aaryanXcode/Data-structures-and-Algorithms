#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
int main()
{
    unordered_map<string,int> ourmap;
    ourmap["abc1"]=1;
    ourmap["abc2"]=2;
    ourmap["abc3"]=3;
    ourmap["abc4"]=4;
    ourmap["abc5"]=5;
    ourmap["abc6"]=6;
    for(auto k:ourmap)
    {
        cout<<k.first<<" "<<k.second<<endl;
    }
    //iterator
    cout<<"iterator"<<endl;
    unordered_map<string,int>:: iterator it=ourmap.begin();
    while(it!=ourmap.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    cout<<"vector"<<endl;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++)
    {
        m[v[i]]++;
    }
    for(auto k:m)
    {
        cout<<k.first<<" "<<k.second<<endl;
    }
    cout<<endl;
    unordered_map<int,int>:: iterator it1=m.begin();
    while(it1!=m.end())
    {
        cout<<it1->first<<" "<<it1->second<<endl;
        it1++;
    }
    it1=m.begin();
    while(it1!=m.end())
    {
        if(it1->second>2)
        {
            it1->second=2;
        }
        it1++;
    }
    it1=m.begin();
    while(it1!=m.end())
    {
        cout<<it1->first<<" "<<it1->second<<endl;
        it1++;
    }
    vector<int> vec;
    while(it1!=m.end())
    {
        for(int i=0;i<it1->second;i++)
        {
            v.push_back(it1->first);
        }
        it1++;
    }
    cout<<"printing vector"<<endl;
  //  vector<int>::iterator itvec=vec.begin();
    /*while(itvec!=vec.end())
    {
        cout<<*itvec<<endl;
        itvec++;
    }
    */
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<",";
    }

}
