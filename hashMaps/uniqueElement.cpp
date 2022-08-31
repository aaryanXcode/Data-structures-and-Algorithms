/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<unordered_map>
#include<vector>
//unique element in sorted array where every element is occuring twice except one.
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(3);
    v.push_back(4);
    v.push_back(4);
    v.push_back(8);
    v.push_back(8);

   unordered_map<int,int> m;
   int k;
  int key=9;

   for(int i=0;i<v.size();i++)
   {
       m[v[i]]++;

   }
   if (m.find(key) == m.end())
        cout << key << " not found\n";
    else
        cout << "Found " << key << endl;
   for(auto k:m)
   {
       cout<<k.first<<" "<<k.second<<endl;
   }

    return 0;
}

