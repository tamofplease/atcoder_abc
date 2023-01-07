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

pair<mint, int> op(const pair<mint, int> a, const pair<mint, int> b) {
    return {a.first + b.first, a.second + b.second};
}
pair<mint, int> e() { return {0, 0}; }

int main() {
    int n;
    cin >> n;
    vector<int> a(n), sorted_a(n);
    map<int, vector<int>> rank;
    rep(i, n) {
        cin >> a[i];
        sorted_a[i] = a[i];
    }
    sort(ALL(sorted_a));
    rrep(i, n) rank[sorted_a[i]].push_back(i);
    segtree<pair<mint, int>, op, e> seg(n);
    mint ans = a[0];

    cout << ans.val() << endl;
    seg.set(rank[a[0]].back(), {a[0], 1});
    rank[a[0]].pop_back();
    for (int i = 1; i < n; i++) {
        ll aa = a[i], cur_rank = rank[a[i]].back();
        rank[aa].pop_back();
        int val = seg.prod(0, cur_rank).second;
        ans += aa * (2 * val + 1);
        seg.set(cur_rank, {aa, 1});
        ans += seg.prod(cur_rank + 1, n).first * 2;
        mint j = i + 1;
        cout << (ans / (j * j)).val() << endl;
    }

    return 0;
}
