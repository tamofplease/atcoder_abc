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
void rec(const vector<vector<int>>& to, vector<ll>& child_count, int prev, int cur) {
    for (int nxt : to[cur]) {
        if (nxt != prev) {
            rec(to, child_count, cur, nxt);
            child_count[cur] += child_count[nxt];
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> to(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v, u--, v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    vector<ll> child_count(n, 1);

    rec(to, child_count, -1, 0);

    auto fill = [&](auto f, int prev, int cur) -> ll {
        ll res = 0;
        for (int nxt : to[cur]) {
            if (nxt == prev) continue;
            res += child_count[nxt] + f(f, cur, nxt);
        }
        return res;
    };
    vector<ll> ans(n, -1);
    ans[0] = fill(fill, -1, 0);
    auto dfs = [&](auto f, int prev, int cur) -> void {
        ans[cur] = ans[prev] - child_count[cur] + n - child_count[cur];
        for (int nxt : to[cur]) {
            if (ans[nxt] != -1) continue;
            f(f, cur, nxt);
        }
    };
    for (int nxt : to[0]) {
        if (ans[nxt] != -1) continue;
        dfs(dfs, 0, nxt);
    }
    for (ll a : ans) cout << a << endl;

    return 0;
}
