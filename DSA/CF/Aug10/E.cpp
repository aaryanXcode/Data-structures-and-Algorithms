#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        vector<unsigned int> a(n);
        vector<unsigned int> b(n);
        for(int i = 0; i<n;i++){
            cin>>a[i];
        }
        for(int i = 0; i<n;i++){
            cin>>b[i];
        }
        bool possible = true;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] != b[i]) {
                a[i] =a[i]^a[i+1];
                if (a[i]!=b[i]) {
                    possible=false;
                    break;
                }
            }
        }
        if (a[n-1]!=b[n-1]) {
            possible = false;
        }
        cout << (possible ? "YES\n" : "NO\n");
    }
}
