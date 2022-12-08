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
    vector<vector<int>> children(n);
    vector<pair<int, int>> p;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        p.emplace_back(a, b);
        children[a].push_back(b);
    }
    ll whole = 0;
    vector<ll> ans(n, 0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t, e;
        ll x;
        cin >> t >> e >> x, e--;
        if (t == 1) {
            ans[p[e].second] -= x;
            whole += x;
        } else if (t == 2) {
            ans[p[e].first] += x;
        }
    }
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (children[i].size()) {
            root = i;
            break;
        }
    }
    vector<bool> been(n, false);
    auto rec = [&](auto f, int cur, ll val) -> void {
        been[cur] = true;
        ans[cur] += val;
        for (int nxt : children[cur]) {
            if (been[nxt]) continue;
            f(f, nxt, val + ans[cur]);
        }
    };
    rec(rec, root, ans[root] + whole);
    return 0;
}
