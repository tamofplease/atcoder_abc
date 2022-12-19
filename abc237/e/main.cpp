// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<ll, int>;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i, n) { cin >> h[i]; }
    vector<vector<int>> to(n);
    map<pair<int, int>, ll> costs;
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        to[u].push_back(v);
        to[v].push_back(u);
        costs[{u, v}] = (h[v] - h[u]) * ((h[u] < h[v]) ? 1 : 0);
        costs[{v, u}] = (h[u] - h[v]) * ((h[v] < h[u]) ? 1 : 0);
    }

    vector<ll> fixed(n, INT64_MAX), floating(n, INT64_MAX);
    floating[0] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, 0);
    ll ans = INT64_MIN;
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        if (fixed[cur] != INT64_MAX) continue;
        fixed[cur] = cost;
        ans = max(h[0] - fixed[cur] - h[cur], ans);
        for (const int nxt : to[cur]) {
            if (fixed[nxt] != INT64_MAX) continue;
            if (cost + costs[{cur, nxt}] < floating[nxt]) {
                floating[nxt] = cost + costs[{cur, nxt}];
                pq.emplace(floating[nxt], nxt);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
