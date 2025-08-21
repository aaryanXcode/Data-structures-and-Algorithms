#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n, m;
        string a, b, c;

        cin >> n;
        cin >> a;
        cin >> m;
        cin >> b;
        cin >> c;
        for(int i = 0; i<c.size(); i++){
            if(c[i]=='V'){
                a = b[i]+a;
            }
            else{
                a = a+b[i];
            }
        }
        cout<<a<<endl;
    }
    return 0;
}