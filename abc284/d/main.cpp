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

std::vector<bool> IsPrime;

void sieve(size_t max) {
    if (max + 1 > IsPrime.size()) {     // resizeで要素数が減らないように
        IsPrime.resize(max + 1, true);  // IsPrimeに必要な要素数を確保
    }
    IsPrime[0] = false;  // 0は素数ではない
    IsPrime[1] = false;  // 1は素数ではない

    for (size_t i = 2; i * i <= max; ++i)          // 0からsqrt(max)まで調べる
        if (IsPrime[i])                            // iが素数ならば
            for (size_t j = 2; i * j <= max; ++j)  // (max以下の)iの倍数は
                IsPrime[i * j] = false;            // 素数ではない
}

int main() {
    int t;
    cin >> t;
    sieve(10000000);
    vector<ll> primes;
    for (ll i = 2; i < 10000000; i++)
        if (IsPrime[i]) primes.push_back(i);
    rep(i, t) {
        ll n;
        cin >> n;
        for (ll prime : primes) {
            if (n % prime == 0) {
                n /= prime;
                if (n % prime == 0) {
                    cout << prime << " " << n / prime << endl;
                } else {
                    cout << (ll)sqrt(n) << " " << prime << endl;
                }
                break;
            }
        }
    }
    return 0;
}
