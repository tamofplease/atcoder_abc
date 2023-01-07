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
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    vector<bool> been(n, false);
    ll ans = 0;
    ll border = 1000000;
    auto dfs = [&](auto f, int cur) -> void {
        been[cur] = true;
        ans++;
        if (ans > border) return;
        for (int nxt : to[cur]) {
            if (been[nxt]) continue;
            f(f, nxt);
        }
        been[cur] = false;
    };

    dfs(dfs, 0);
    cout << min(ans, border) << endl;

    return 0;
}
