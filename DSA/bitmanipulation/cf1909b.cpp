#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){ 
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i = 0; i<n; i++){
            cin>>v[i];
        }

        bool found = false;
        for (int i = 1; i <= 61; i++) {
            ll num = (1ll<<i); 
            set<ll> st;
            for (int j = 0; j < n; j++) {
                st.insert(v[j]%num);
            }
            if (st.size() == 2) {
                cout << num << endl;
                found = true;
                break;   
            }
        }
        if (!found) cout << (1ll<<60) << endl;
    }
    return 0;
}