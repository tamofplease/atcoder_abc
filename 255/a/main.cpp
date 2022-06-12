// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    int r, c;
    cin >> r >> c;
    vector<vector<int>> a(2, vector<int>(2, 0));
    rep(i, 2) rep(j, 2) { cin >> a[i][j]; }
    cout << a[r - 1][c - 1] << endl;
    return 0;
}
