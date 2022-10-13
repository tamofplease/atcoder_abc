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
using mint = modint1000000007;
// using mint = modint998244353;

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

void show(vector<vector<mint>>& t) {
    for (vector<mint> tt : t) {
        for (mint ttt : tt) {
            cout << ttt.val() << " ";
        }
        cout << endl;
    }
}

int main() {
    mint ans = 0;
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<mint>> dp(h, vector<mint>(w, 0)), x(h, vector<mint>(w, 0)), y(h, vector<mint>(w, 0)),
        xy(h, vector<mint>(w, 0));
    for (auto& ref : s) cin >> ref;
    dp[0][0] = 1, x[0][0] = 1, y[0][0] = 1, xy[0][0] = 1;
    rep(i, h) rep(j, w) {
        if (i == 0 && j == 0) continue;
        if (s[i][j] == '#') continue;
        if (j) x[i][j] += x[i][j - 1];
        if (i) y[i][j] += y[i - 1][j];
        if (i && j) xy[i][j] += xy[i - 1][j - 1];
        dp[i][j] += x[i][j] + y[i][j] + xy[i][j];
        x[i][j] += dp[i][j];
        y[i][j] += dp[i][j];
        xy[i][j] += dp[i][j];
    }
    cout << dp[h - 1][w - 1].val() << endl;
    return 0;
}
