#include <bits/stdc++.h>
using namespace std;

int main() {
   
    int t;
    cin>>t;
    while(t--){
        int k,x;
        cin>>k>>x;

        while (k--) {
            if ((x-1) % 3 == 0) {
                int prev = (x-1)/3;
                if (prev % 2 == 1) {
                    x = prev;
                    continue;
                }
            }
            x = 2 * x;
        }
        cout<<x<<"\n";
    }
    return 0;
}
