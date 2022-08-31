#include<iostream>
using namespace std;
class Triplet
{
public:
    int x;
    int y;
    int gcd;
};
Triplet extendedEuclid(int a ,int b)
{
    //base case
    if(b==0)
    {
        Triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }
    //extended Euclid Algorithm
    Triplet smallAns=extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd=smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}
int main()
{
    int a=16;
    int b=10;
    Triplet ans=extendedEuclid(a,b);
    cout<<ans.gcd<<endl;
    cout<<ans.x<<endl;
    cout<<ans.y<<endl;
}
