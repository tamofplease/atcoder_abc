// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

struct Edge {
    ll cost;
    int to;
    Edge(ll cost, int to) : cost(cost), to(to) {}
};

int main() {
    // 1. 有効グラフを作成する
    // 2. 拡張点に対して
    // 2.1 全ての頂点へ到達することができる最小のpを2分探索で求める。
    // 3. 2.のうちの最小のpが答え
    int n;
    cin >> n;
    vector<vector<Edge>> g(n);

    vector<ll> x(n), y(n), p(n);
    rep(i, n) { cin >> x[i] >> y[i] >> p[i]; }
    rep(i, n) {
        rep(j, i) {
            ll eu = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            g[i].emplace_back(eu, j);
            g[j].emplace_back(eu, i);
        }
    }
    auto isValid = [&](int init, ll border, vector<bool> been) -> bool {
        queue<int> q;
        q.push(init);
        been[init] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (Edge e : g[cur]) {
                if (!been[e.to] && e.cost <= p[cur] * border) {
                    q.push(e.to);
                    been[e.to] = true;
                }
            }
        }
        return all_of(been.begin(), been.end(), [](bool v) { return v; });
    };
    auto doBinSearch = [&](int cur) -> ll {
        ll invalid = 0, valid = 4000000001;
        while (valid - invalid > 1) {
            ll mid = (invalid + valid) / 2;
            vector<bool> been(n, false);
            (isValid(cur, mid, been) ? valid : invalid) = mid;
        }
        return valid;
    };
    ll ans = INT64_MAX;

    rep(i, n) { ans = min(ans, doBinSearch(i)); }
    cout << ans << endl;
    return 0;
}
