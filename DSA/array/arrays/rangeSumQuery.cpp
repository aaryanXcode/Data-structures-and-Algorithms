#include<vector>
#include <iostream>
using namespace std;

long long solve(vector<long long>& pre, int l, int r){
    l--,r--;
    if (l == 0) return pre[r]; 
    return pre[r] - pre[l-1];
}
int main(){
    int n, q;
    cin>>n>>q;
    vector<long long> v(n);
    for (auto &it : v) {
        cin >> it;
    }
   
    for(int i = 1; i<n ;i++){
        v[i] = v[i]+v[i-1];
    }

    while(q--){
        long long l,r;
        cin>>l>>r;

        long long ans = solve(v,l,r);
        cout<<ans<<endl;
    }
    return 0;
}
