#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll solve(ll a, ll b) {
    ll sum = a + b;
    if (sum % 2 == 0) return sum;
    if (b % 2 == 0) {
        sum = 2 * a + b / 2;
        if (sum % 2 == 0) return sum;
    }
    if (b % 2 == 1) {
        if (a % 2 == 1) {
            sum = a * b + 1;
            return sum;
        } else {
            return -1;
        }
    }
    return -1;
}

int main(){
    int t ;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        ll ans = solve(a,b);
        cout<<ans<<"\n";
    }
    return 0;;
}