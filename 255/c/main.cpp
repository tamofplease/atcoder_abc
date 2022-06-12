// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    x -= a;
    if (d == 0) {
        cout << abs(x) << endl;
        return 0;
    }
    n--;
    if (n == 0) {
        cout << abs(x) << endl;
        return 0;
    }
    if (0 < d) {
        ll last = n * d;
        if (x <= 0) {
            cout << abs(x) << endl;
            return 0;
        }
        if (last <= x) {
            cout << x - last << endl;
            return 0;
        } else {
            ll rp = x / d;
            cout << min(abs(x - rp * d), abs((rp + 1) * d - x)) << endl;
            return 0;
        }
    } else {
        ll first = n * d;
        if (x >= 0) {
            cout << abs(x) << endl;
            return 0;
        }
        if (x <= first) {
            cout << first - x << endl;
            return 0;
        } else {
            ll rp = x / d;
            cout << min(abs(x - rp * d), abs((rp + 1) * d - x)) << endl;
        }
    }
    return 0;
}
