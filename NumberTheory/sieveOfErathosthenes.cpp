#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=0;

    bool *prime=new bool[n];
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i<n;i++)
    {
        prime[i]=true;
    }
    for(int i=2;i<=n;i++)
    {
        cout<<prime[i]<<" ";
    }
    cout<<endl;
    for(int i=2;i*i<=n;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {

                prime[j]=false;
            }
        }

    }
    cout<<"\nprinting prime array"<<endl;
    for(int i=2;i<=n;i++)
    {
        cout<<prime[i]<<" ";
    }

    cout<<"\ntotal prime in range 2 to "<<n<<endl;

    for(int i=0;i<=n;i++)
    {
        if(prime[i]==true)
        {
            count++;
        }
    }
    cout<<count<<endl;
}
