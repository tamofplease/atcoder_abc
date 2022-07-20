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
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
};

int main() {
    int n;
    cin >> n;
    vector<int> colors(n, -1);
    vector<vector<Edge>> g(n);
    rep(i, n - 1) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [cur, color] = q.front();
        q.pop();
        colors[cur] = color;
        for (Edge nxt : g[cur]) {
            if (colors[nxt.to] != -1) {
                continue;
            }
            q.emplace(nxt.to, nxt.cost % 2 ? 1 - color : color);
        }
    }
    for (int color : colors)
        cout << color << endl;
    return 0;
}
