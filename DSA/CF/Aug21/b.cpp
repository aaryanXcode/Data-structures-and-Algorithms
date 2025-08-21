#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> results;
        ll power = 10;
        for (int k = 1; k <= 18; k++) {
            if (power >= n) break;
            ll divisor = 1 + power;
            if (n % divisor == 0) {
                results.push_back(n/divisor);
            }
            power*=10;
        }
        if (results.empty()) {
            cout << 0 << "\n";
        } else {
            sort(results.begin(), results.end());
            cout << results.size() << "\n";
            for (auto x : results) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}
