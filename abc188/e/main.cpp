// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

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
    vector<int> a(n);
    vector<vector<int>> to(n);
    rep(i, n) cin >> a[i];
    rep(i, m) {
        int x, y;
        cin >> x >> y, x--, y--;
        to[x].push_back(y);
    }
    vector<int> sell(n, INT32_MIN);
    int ans = INT32_MIN;
    auto dfs = [&](auto f, int cur, int buy) -> void {
        if (sell[cur] != INT32_MIN) return;
        for (const int nxt : to[cur]) {
            f(f, nxt, min(buy, a[nxt]));
            chmax(sell[cur], max(sell[nxt], a[nxt]));
        }
    };
    for (int i = 0; i < n; i++) {
        dfs(dfs, i, a[i]);
        if (sell[i] == INT32_MIN) continue;
        ans = max(ans, sell[i] - a[i]);
    }
    cout << ans << endl;
    return 0;
}
