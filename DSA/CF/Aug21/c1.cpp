#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    int maxm = 18;

    vector<ll> meloncount(maxm+1), cost(maxm+1);
    meloncount[0] = 1;
    for(int i = 1; i<=maxm; i++){
        meloncount[i] = meloncount[i-1]*3;
    }

    for(int x = 0; x<=maxm; x++){
        if(x==0)
        {
            cost[x] = 3;

        }
        else{
            cost[x] = meloncount[x+1] + (ll)x * meloncount[x-1];
        }
    }
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll totalcost  = 0;
        while(n>0){
            int x = upper_bound(meloncount.begin(), meloncount.end(), n)-meloncount.begin()-1;
            totalcost += cost[x];
            n -= meloncount[x];
        }
        cout<<totalcost<<"\n";
    }
    return 0;
}