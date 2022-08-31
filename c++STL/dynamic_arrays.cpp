#include<iostream>
#include<array>
using namespace std;
int main()
{
    array<int,4> a={1,2,3,4};
    int size=a.size();
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"at index"<<a.at(2)<<endl;
    cout<<"is empty"<<a.empty()<<endl;
    cout<<"front element"<<a.front()<<endl;
    cout<<"last element"<<a.back()<<endl;

}
