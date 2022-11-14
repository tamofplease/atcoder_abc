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

const int MOD = 998244353;

int main() {
    ll a = 1, b = 1, c;
    rep(i, 6) {
        cin >> c;
        c %= MOD;
        if (i < 3) {
            a *= c;
            a %= MOD;
        } else {
            b *= c;
            b %= MOD;
        }
    }
    ll ans = (a - b + MOD) % MOD;
    std::cout << ans << endl;
    return 0;
}
