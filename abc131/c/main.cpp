// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    a--;
    ll gc = lcm(c, d);
    ans += b - (b / c) - (b / d) + (b / gc);
    ans -= (a - (a / c) - (a / d) + (a / gc));
    cout << ans << endl;
    return 0;
}