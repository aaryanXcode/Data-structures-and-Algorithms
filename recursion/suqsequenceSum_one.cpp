
#include<bits/stdc++.h>
using namespace std;
using namespace std;
bool subsequenceSumK(int index, vector<int> &v,int a[],int n,int s,int sum)
{
    if(index==n)
    {
        if(s==sum)
        {
            for(auto i:v)
            {
                cout<<i<<" ";
            }
        cout<<endl;
        return true;
        }

        return false;
    }
    v.push_back(a[index]);
    sum+=a[index];
    if(subsequenceSumK(index+1,v,a,n,s,sum)==true)
        return true;

    sum-=a[index];
    v.pop_back();

    if(subsequenceSumK(index+1,v,a,n,s,sum)==true)
        return true;
    return false;
}
int main()
{
    int a[5]={1,2,3,4,5};
    int n=5;
    int s=5;
    vector<int> v;
    subsequenceSumK(0,v,a,n,s,0);
}
