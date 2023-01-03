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
    int n;
    cin >> n;
    vector<vector<int>> edges;
    vector<int> depth(n, 0);
    vector<unordered_set<int>> to(n);
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b, a--, b--;
        edges.push_back({a, b});
        to[a].insert(b);
        to[b].insert(a);
    }
    auto dfs1 = [&](auto f, int cur, int prev) -> void {
        if (prev != -1) depth[cur] = depth[prev] + 1;
        for (int nxt : to[cur]) {
            if (nxt == prev) continue;
            f(f, nxt, cur);
        }
    };
    depth[0] = 1;
    dfs1(dfs1, 0, -1);
    for (vector<int> edge : edges) {
        if (depth[edge[0]] < depth[edge[1]]) swap(edge[0], edge[1]);
        to[edge[0]].erase(edge[1]);
    };
    ll sum = 0;
    vector<ll> ans(n, 0);
    int q;
    cin >> q;
    rep(i, q) {
        int t, e, x;
        cin >> t >> e >> x, e--;
        vector<int> edge = edges[e];
        if (t == 2) swap(edge[0], edge[1]);
        if (depth[edge[0]] < depth[edge[1]]) {
            sum += x;
            ans[edge[1]] -= x;
        } else {
            ans[edge[0]] += x;
        }
    }
    auto dfs = [&](auto f, int idx) -> void {
        for (int nxt : to[idx]) {
            ans[nxt] += ans[idx];
            f(f, nxt);
        }
    };
    ans[0] += sum;
    dfs(dfs, 0);
    for (const ll a : ans) cout << a << endl;
    return 0;
}
