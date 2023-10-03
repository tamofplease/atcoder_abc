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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b, a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    priority_queue<pair<int, int>> pq;
    vector<int> memo(n, -1);
    rep(i, k) {
        int p, h;
        cin >> p >> h, p--;
        pq.emplace(h, p);
        memo[p] = h;
    }
    while (!pq.empty()) {
        auto [h, cur] = pq.top();
        h--;
        pq.pop();
        for (int nxt : g[cur]) {
            if (h > memo[nxt]) {
                pq.emplace(h, nxt);
                memo[nxt] = h;
            }
        }
    }

    int ans = 0;
    rep(i, n) {
        if (memo[i] != -1) ans++;
    }
    cout << ans << endl;
    rep(i, n) {
        if (memo[i] != -1) cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}
