#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    //creation
    unordered_map<string,int> m; //if we use map in place of unordered map it will stored in sorted manner ex as we creating map map will printed on these manner.

    //insertion
    //1
    pair<string,int> p=make_pair("aryan",3);
    m.insert(p);

    //2
    pair<string,int> pair2("raj",2);
    m.insert(pair2);

    //3
    m["mera"]=1;
    m["mera"]=2;

    //searching
    cout<<m["mera"]<<endl;
    cout<<m.at("aryan")<<endl;
    //cout<<m["unknown"]<<endl; if not exist in map it will create a map with key
    //cout<<m.at("unknown")<<endl;//now here a new entry made by previous line so it will o/p value at that posiition
    //if previous line has not written their than it will show an error that key is not in map or out of bound etc.

   cout<<m["unknown"]<<endl;
   cout<<m.count("aryan")<<endl;


    m.erase("unknown");
    cout<<m.size()<<endl;

    cout<<"printing set value"<<endl;
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }


    //iterator
    cout<<"print using iterator"<<endl;
    unordered_map<string,int> :: iterator it=m.begin();
    while(it!=m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;


}
