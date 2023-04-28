// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

using mint = modint998244353;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m);
    for (auto& ref : a) cin >> ref, ref--;
    vector<vector<int>> to(n);
    map<pair<int, int>, int> mm;
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v, u--, v--;
        to[u].push_back(v);
        to[v].push_back(u);
        mm[{u, v}] = i;
        mm[{v, u}] = i;
    }
    map<pair<int, int>, vector<int>> ma;

    // start <= goal
    auto dfs = [&](auto f, int cur, int prev, int start, int goal) -> bool {
        if (prev != -1) ma[{start, goal}].push_back(mm[{prev, cur}]);
        if (cur == goal) return true;

        for (const int nxt : to[cur]) {
            if (nxt == prev) continue;
            if (f(f, nxt, cur, start, goal)) return true;
        }

        if (ma[{start, goal}].size()) ma[{start, goal}].pop_back();
        return false;
    };

    for (int i = 0; i < m - 1; i++) {
        int goal = a[i + 1], start = a[i];
        if (start > goal) swap(start, goal);
        if (ma.count({start, goal})) continue;
        dfs(dfs, start, -1, start, goal);
    }

    vector<int> memo(n - 1, 0);
    rep(i, m - 1) {
        int goal = a[i + 1], start = a[i];
        if (start > goal) swap(start, goal);
        for (int ii : ma[{start, goal}]) memo[ii]++;
    }

    map<ll, mint> dp;
    dp[0] = 1;

    // sum = r + b;
    // r = b + k;

    for (int i = 0; i < n - 1; i++) {
        map<ll, mint> nxt = dp;
        for (pair<int, mint> j : dp) {
            nxt[j.first + memo[i]] += j.second;
            nxt[j.first - memo[i]] += j.second;
        }
        dp = move(nxt);
        cout << dp.size() << endl;
    }
    cout << dp[k].val() << endl;

    return 0;
}
