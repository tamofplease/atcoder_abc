// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

using ll = int64_t;

using P = pair<ll, int>;

struct Edge {
    int to, cost, id;
    Edge(int to, int cost, int id) : to(to), cost(cost), id(id) {}
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].emplace_back(b, c, i + 1);
        g[b].emplace_back(a, c, i + 1);
    }
    const ll INF = 1e18;
    vector<ll> dist(n, INF);
    vector<int> from(n, -1);
    priority_queue<P, vector<P>, greater<P>> q;
    dist[0] = 0;
    q.emplace(0, 0);

    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();
        if (dist[v] != d)
            continue;
        for (auto [u, cost, id] : g[v]) {
            ll nd = d + cost;
            if (dist[u] <= nd) {
                continue;
            }
            dist[u] = nd;
            from[u] = id;
            q.emplace(nd, u);
        }
    }

    for (int i = 1; i < n; i++) {
        cout << from[i] << endl;
    }
    return 0;
}