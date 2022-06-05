// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(1 + n, vector<int>(n, 0));
    a[0][0] = 1;
    for (int i = 0; i <= n - 1; i++) {
        rep(j, i + 1) {
            if (j == 0 || i == j) {
                a[i][j] = 1;
            } else {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }
    }
    rep(i, n) {
        rep(j, i + 1) { cout << a[i][j] << " "; }
        cout << endl;
    }
    return 0;
}
