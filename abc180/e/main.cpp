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

struct City {
    int a, b, c;
    City(int a, int b, int c) : a(a), b(b), c(c) {}
    int move_to(City other) { return abs(other.a - a) + abs(other.b - b) + max(0, other.c - c); }
};

int main() {
    int n;
    cin >> n;
    vector<City> cities;
    rep(i, n) {
        int a, b, c;
        cin >> a >> b >> c;
        cities.emplace_back(a, b, c);
    }
    vector<vector<int>> dp(n + 1, vector<int>((1 << n), INT32_MAX));
    // dp[i][j]: 現在地がi番目、j訪問ずみにおける最小コスト
    dp[0][0] = 0;
    for (int cur = 0; cur < (1 << n); cur++) {
        for (int to = 0; to < n; to++) {
            int nxt = (1 << to | cur);
            if (cur == nxt) continue;
            for (int from = 0; from < n; from++)
                if (dp[from][cur] != INT32_MAX) chmin(dp[to][nxt], dp[from][cur] + cities[from].move_to(cities[to]));
        }
    }
    cout << dp[0][(1 << n) - 1] << endl;
    return 0;
}
