#include <bits/stdc++.h>
using namespace std;

void generateCombinations(vector<char>& arr, int l, int r, int k, vector<char>& current) {
    if (current.size() == k) {
        for (auto ch : current) cout << ch;
        cout << "\n";
        return;
    }

    for (int i = l; i <= r; i++) {
        current.push_back(arr[i]);                              // choose element
        generateCombinations(arr, i + 1, r, k, current);        // recurse ahead
        current.pop_back();                                     // backtrack
    }
}

int main() {
    vector<char> arr = {'a','b','c','d','e'};
    int k = 4;

    vector<char> current;
    generateCombinations(arr, 0, arr.size() - 1, k, current);

    return 0;
}
