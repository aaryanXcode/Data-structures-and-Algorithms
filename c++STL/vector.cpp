#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout<<"size of vector"<<v.size() <<endl;
    cout<<v.capacity() <<endl;
    cout<<v.front() <<endl;
    cout<<v.back() <<endl;
    for(int i:v)
    {
        cout<<i<<" ";
    }

}



