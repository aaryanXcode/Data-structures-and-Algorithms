#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        vector<long long> s(n);
        vector<long long> t(n);

        for (int i =0;i<n;i++)
        {
            cin>>s[i];
        } 
        for (int i =0;i<n;i++){
            cin>>t[i];
        } 

        for (int i = 0; i<n; i++) {
            s[i] %= k;
            if(s[i]>k-s[i])
            {
                s[i]=k-s[i];
            } 
        }
        for (int i = 0; i<n; i++) {
            t[i] %= k;
            if (t[i]>k-t[i]) {
                t[i]=k-t[i];
            }
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s==t){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}