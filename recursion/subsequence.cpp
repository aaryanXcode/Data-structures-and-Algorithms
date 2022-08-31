#include<bits/stdc++.h>
using namespace std;
void subsequence(int index, vector<int> &v,int a[],int n)
{
    if(index==n)
    {
        for(auto i:v)
        {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    v.push_back(a[index]);
    subsequence(index+1,v,a,n);
    v.pop_back();

    subsequence(index+1,v,a,n);

}
int main()
{
    int a[3]={1,2,3};
    vector<int> v;
    subsequence(0,v,a,3);

}


