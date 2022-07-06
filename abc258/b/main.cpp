// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    int ma = 0;
    vector<pair<int, int>> maxGrids;
    rep(i, n) {
        cin >> grid[i];
        rep(j, n) { ma = max(ma, grid[i][j] - '0'); }
    }
    rep(i, n) rep(j, n) {
        if (grid[i][j] - '0' == ma) {
            maxGrids.emplace_back(i, j);
        }
    }
    int d[3] = {-1, 0, 1};

    ll ans = 0;
    for (pair<int, int> i : maxGrids) {
        for (int dc : d)
            for (int dr : d) {
                int r = i.first, c = i.second;
                if (dc == 0 && dr == 0)
                    continue;
                ll tmp = grid[r][c] - '0';
                rep(i, n - 1) {
                    c = (n + dc + c) % n;
                    r = (n + dr + r) % n;
                    tmp *= 10;
                    tmp += grid[r][c] - '0';
                }
                ans = max(ans, tmp);
            }
    }
    cout << ans << endl;
    return 0;
}
