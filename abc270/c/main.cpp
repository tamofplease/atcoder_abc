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
    int n, x, y;
    cin >> n >> x >> y, x--, y--;
    vector<vector<int>> to(n, vector<int>());
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v, u--, v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    auto rec = [&](auto f, int cur, int prev, vector<int>& v) -> bool {
        v.push_back(cur);
        if (cur == y) return true;
        for (int nxt : to[cur]) {
            if (nxt != prev && f(f, nxt, cur, v)) return true;
        }
        v.pop_back();
        return false;
    };

    vector<int> v;
    rec(rec, x, -1, v);
    for (int a : v) cout << a + 1 << (a == v.back() ? "\n" : " ");

    return 0;
}
