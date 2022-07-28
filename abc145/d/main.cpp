// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

ll pow_mod(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll d = pow_mod(a, b / 2);
        return (d * d) % MOD;
    }
    return (a * pow_mod(a, b - 1)) % MOD;
}

ll comb(ll n, ll c) {
    ll up = 1, down = 1;
    Rep(i, c) {
        up = (up * n) % MOD;
        down = (down * i) % MOD;
        n -= 1;
    }
    return (up * pow_mod(down, MOD - 2)) % MOD;
}

int main() {
    int x, y;
    cin >> x >> y;
    if ((2 * x - y) % 3 != 0 || (2 * y - x) % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll X = (2 * x - y) / 3;
    ll Y = (2 * y - x) / 3;
    if (X < 0 || Y < 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << comb(X + Y, Y) << endl;
    return 0;
}
