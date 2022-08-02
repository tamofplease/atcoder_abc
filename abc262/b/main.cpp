// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> to(n, vector<bool>(n, false));
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        to[u][v] = true;
        to[v][u] = true;
    }
    int ans = 0;
    rep(a, n) rep(b, a) rep(c, b) {
        if (to[a][b] && to[b][c] && to[c][a]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
