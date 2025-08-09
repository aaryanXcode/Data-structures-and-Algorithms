#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;

    vector<long long> v(n);
    for(auto &it: v){
        cin>>it;
    }

    long long ans = 0;
    long long sum = 0;
    unordered_map<long long, long long> mp;
    for(int i = 0;i<n;i++){
        sum += v[i];
        ans += mp[sum-x];
        if(sum ==x) ans++;
        mp[sum]++;

    }
    cout<<ans<<endl;
    
    
}