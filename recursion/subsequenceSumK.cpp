#include<bits/stdc++.h>
using namespace std;
using namespace std;
void subsequenceSumK(int index, vector<int> &v,int a[],int n,int s,int sum)
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
        }

        return;
    }
    v.push_back(a[index]);
    sum+=a[index];
    subsequenceSumK(index+1,v,a,n,s,sum);
    v.pop_back();
    sum-=a[index];

    subsequenceSumK(index+1,v,a,n,s,sum);

}
int main()
{
    int a[5]={1,2,3,4,5};
    int n=5;
    int s=5;
    vector<int> v;
    subsequenceSumK(0,v,a,n,s,0);
}
