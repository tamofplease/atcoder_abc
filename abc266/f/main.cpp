// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define rRep(i, n) for (int i = n; i >= 1; i--)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;
// using mint = modint1000000007;
using mint = modint998244353;

const int MOD = 1000000007;

template <typename T, int FAC_MAX>
struct Comb {
   private:
    vector<T> fac, ifac;

   public:
    Comb() {
        fac.resize(FAC_MAX, 1);
        ifac.resize(FAC_MAX, 1);
        Rep(i, FAC_MAX - 1) fac[i] = fac[i - 1] * i;
        ifac[FAC_MAX - 1] = T(1) / fac[FAC_MAX - 1];
        rRep(i, FAC_MAX - 2) ifac[i] = ifac[i + 1] * T(i + 1);
    }
    T aPb(int a, int b) {
        if (b < 0 || a < b) return T(0);
        return fac[a] * ifac[a - b];
    }
    T aCb(int a, int b) {
        if (b < 0 || a < b) return T(0);
        return fac[a] * ifac[a - b] * ifac[b];
    }
    T nHk(int n, int k) {
        if (n == 0 && k == 0) return T(1);
        if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k);
    }
    T pairCombination(int n) {
        if (n % 2 == 1) return T(0);
        return fac[n] * ifac[n / 2] / (T(2) ^ (n / 2));
    }
};

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> edge;
    vector<bool> been(n, false);
    vector<vector<int>> to(n);
    rep(i, n) {
        int u, v;
        cin >> u >> v, u--, v--;
        edge.emplace_back(u, v);
        to[v].push_back(u);
        to[u].push_back(v);
    }
    vector<bool> contents(n, false);
    auto dfs = [&](auto f, int cur, int prev = -1) -> int {
        if (been[cur]) {
            contents[cur] = true;
            return cur;
        }
        been[cur] = true;
        for (int nxt : to[cur]) {
            if (nxt == prev) continue;
            int res = f(f, nxt, cur);
            if (res == -1) continue;
            if (res == cur) return -1;
            contents[cur] = true;
            return res;
        }
        return -1;
    };
    dfs(dfs, 0);
    dsu d(n);
    for (auto [u, v] : edge) {
        if (contents[u] && contents[v]) continue;
        d.merge(u, v);
    }
    int q;
    cin >> q;
    rep(i, q) {
        int x, y;
        cin >> x >> y, x--, y--;
        d.same(x, y) ? puts("Yes") : puts("No");
    }
    return 0;
}
