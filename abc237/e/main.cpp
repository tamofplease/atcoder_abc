// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

struct Edge {
    ll cost;
    int to;
    Edge(ll cost, int to) : cost(cost), to(to) {}
};

using P = pair<ll, ll>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    for (auto& ref : h) cin >> ref;
    vector<vector<Edge>> g(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        if (h[u] < h[v]) {
            g[u].emplace_back(h[v] - h[u], u);
            g[v].emplace_back(0, v);
            continue;
        }
        g[v].emplace_back(h[u] - h[v], v);
        g[u].emplace_back(0, u);
    }
    priority_queue<P, vector<P>, greater<P>> q;
    vector<bool> been(n, false);
    vector<ll> costs(n, INT64_MAX);
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [_, cur] = q.top();
        q.pop();
        been[cur] = true;
        for (auto [nxt, cost] : g[cur]) {
            if (been[nxt]) {
                continue;
            }
            if (costs[nxt] > costs[cur] + cost) {
                costs[nxt] = costs[cur] + cost;
                q.emplace(costs[nxt], nxt);
            }
        }
    }
    ll ans = INT64_MAX;
    Rep(i, n - 1) {
        ans = min(ans, h[i] + costs[i]);
    }
    cout << ans << endl;



    return 0;
}
