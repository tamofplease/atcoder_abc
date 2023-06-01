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

    vector<vector<int>> to(n);

    vector<vector<bool>> edges(n, vector<bool>(n, false));
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        to[u].push_back(v);
    }
    auto dfs = [&](auto f, int start, int cur) -> void {
        for (int nxt : to[cur]) {
            if (!edges[start][nxt] && start != nxt) {
                edges[start][nxt] = true;
                f(f, start, nxt);
            }
        }
    };

    for (int i = 0; i < n; i++) {
        dfs(dfs, i, i);
    }

    int ans = 0;
    rep(i, n) rep(j, n) {
        if (edges[i][j]) ans++;
    }
    cout << ans - m << endl;
    return 0;
}
