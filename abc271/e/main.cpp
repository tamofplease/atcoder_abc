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
struct Edge {
    int from, to, cost;
    Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<Edge> graph;
    vector<Edge*> e;
    rep(i, m) {
        int from, to, cost;
        cin >> from >> to >> cost, from--, to--;
        graph.emplace_back(from, to, cost);
    }

    rep(i, k) {
        int ref;
        cin >> ref, ref--;
        e.push_back(&graph[ref]);
    }
    vector<ll> minCosts(n, __INT64_MAX__);
    minCosts[0] = 0;
    for (const Edge* ref : e) {
        if (minCosts[ref->from] != __INT64_MAX__) {
            chmin(minCosts[ref->to], minCosts[ref->from] + ref->cost);
        }
    }
    if (minCosts[n - 1] == __INT64_MAX__)
        cout << -1 << endl;
    else
        cout << minCosts[n - 1] << endl;
    return 0;
}
