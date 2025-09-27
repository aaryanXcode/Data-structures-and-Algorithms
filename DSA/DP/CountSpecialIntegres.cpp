#include <bits/stdc++.h>
using namespace std;

string canonical(int x) {
    string s = to_string(x);
    sort(s.begin(), s.end());  // canonical = sorted digits
    return s;
}

int main() {
    unordered_map<string, int> seen;
    vector<string> order;  // to preserve discovery order

    for (int i = 1; i <= 9999; ++i) {
        string key = canonical(i);
        if (!seen.count(key)) {
            seen[key] = 1;        // mark as seen
            order.push_back(key); // store for printing later
        }
    }

    cout << "Unique groups: " << seen.size() << "\n\n";
    cout << "Digit multisets:\n";

    // Print them grouped by length
    for (int len = 1; len <= 4; ++len) {
        cout << "--- " << len << "-digit multisets ---\n";
        for (auto &key : order) {
            if ((int)key.size() == len) {
                cout << key << " ";
            }
        }
        cout << "\n\n";
    }

    return 0;
}
