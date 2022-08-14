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
    int n, m, e;
    cin >> n >> m >> e;
    vector<pair<int, int>> edge;
    rep(i, e) {
        int u, v;
        cin >> u >> v, u--, v--;
        edge.emplace_back(u, v);
    }
    int q;
    cin >> q;
    vector<int> x(q);
    vector<bool> skip(e, false);
    rep(i, q) {
        cin >> x[i], x[i]--;
        skip[x[i]] = true;
    }
    vector<int> lightNum(n + m, 1);
    rep(i, n) lightNum[i] = 0;
    dsu d(n + m);
    int cur = 0;
    vector<int> ans;
    rep(i, e) {
        if (skip[i]) continue;
        auto [u, v] = edge[i];
        int ul = d.leader(u), vl = d.leader(v);
        if (d.same(u, v)) continue;
        int s = lightNum[ul] + lightNum[vl];
        lightNum[ul] = s, lightNum[vl] = s;
        d.merge(u, v);
    }
    for (auto v : d.groups()) {
        if (lightNum[d.leader(v[0])]) cur += v.size() - lightNum[d.leader(v[0])];
    }
    ans.push_back(cur);
    rRep(i, q - 1) {
        auto [u, v] = edge[x[i]];
        int ul = d.leader(u), vl = d.leader(v);
        if (d.same(u, v)) {
            ans.push_back(cur);
            continue;
        }
        int s = lightNum[ul] + lightNum[vl];
        if (lightNum[ul] == 0 && s > 0) {
            cur += d.size(ul);
        }
        if (lightNum[vl] == 0 && s > 0) {
            cur += d.size(vl);
        }
        lightNum[ul] = s, lightNum[vl] = s;
        ans.push_back(cur);
        d.merge(u, v);
    }

    reverse(ALL(ans));
    for (int a : ans) cout << a << endl;

    return 0;
}
