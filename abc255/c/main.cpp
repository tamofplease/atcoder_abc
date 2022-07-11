// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    ll end = a + (n - 1) * d;
    if (d == 0) {
        cout << abs(a - x) << endl;
        return 0;
    }
    if ((d > 0 && x >= end) || (d < 0 && x <= end)) {
        cout << abs(x - end) << endl;
        return 0;
    }
    if ((d > 0 && x <= a) || (d < 0 && x >= a)) {
        cout << abs(a - x) << endl;
        return 0;
    }

    x -= a;
    ll k = x / d;

    cout << min(abs((k * d) - x), abs(((k + 1) * d) - x)) << endl;

    return 0;
}
