#include <bits/stdc++.h>
using namespace std;

void generateCombinations(string &s, int l, int r, int k, string &current) {
    if (current.size() == k) {
        cout << current << "\n";
        return;
    }

    for (int i = l; i <= r; i++) {
        current.push_back(s[i]);                        // choose this char
        generateCombinations(s, i + 1, r, k, current);  // move ahead
        current.pop_back();                             // backtrack
    }
}

int main() {
    string s = "abcde";
    int k = 4;   // combination length

    string current;
    generateCombinations(s, 0, s.size() - 1, k, current);

    return 0;
}
