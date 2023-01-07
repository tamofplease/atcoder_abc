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
    int n, u, v;
    cin >> n >> u >> v, u--, v--;
    vector<vector<int>> to(n);
    vector<int> dist_t(n, INT32_MAX), dist_a(n, INT32_MAX);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b, a--, b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    auto dfs = [&](auto f, vector<int>& dist, int cur, int prev) -> void {
        dist[cur] = dist[prev] + 1;
        for (int nxt : to[cur]) {
            if (dist[nxt] != INT32_MAX) continue;
            f(f, dist, nxt, cur);
        }
    };
    dist_t[u] = 0;
    dist_a[v] = 0;
    for (int nxt : to[u]) {
        dfs(dfs, dist_t, nxt, u);
    }
    for (int nxt : to[v]) {
        dfs(dfs, dist_a, nxt, v);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dist_a[i] > dist_t[i]) {
            ans = max(ans, dist_a[i] - 1);
        }
    }
    cout << ans << endl;
    return 0;
}
