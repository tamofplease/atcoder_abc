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
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    vector<map<int, int>> v(n);
    rep(i, n) { v[i] = {{c[i], 1}}; }

    dsu d(n);
    rep(i, q) {
        int t;
        cin >> t;
        if (t == 2) {
            int x, y;
            cin >> x >> y, x--;
            int leader = d.leader(x);
            cout << v[leader][y] << endl;
            continue;
        }
        int a, b;
        cin >> a >> b, a--, b--;
        if (d.same(a, b)) continue;
        int a_l = d.leader(a), b_l = d.leader(b);
        int new_leader = d.merge(a, b);
        int abolished_leader = a_l ^ b_l ^ new_leader;
        for (const pair<int, int>& p : v[abolished_leader]) {
            v[new_leader][p.first] += p.second;
        }
    }
    return 0;
}
