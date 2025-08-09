#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> pre(n, vector<int>(m, 0));

    // Build prefix sum
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i][j] = v[i][j];
            if (i > 0) pre[i][j] += pre[i-1][j];
            if (j > 0) pre[i][j] += pre[i][j-1];
            if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l1, r1, l2, r2; // 0-indexed
        cin >> l1 >> r1 >> l2 >> r2;

        int ans = pre[l2][r2];
        if (l1 > 0) ans -= pre[l1-1][r2];
        if (r1 > 0) ans -= pre[l2][r1-1];
        if (l1 > 0 && r1 > 0) ans += pre[l1-1][r1-1];

        cout << "ans: " << ans << endl;
    }
}
