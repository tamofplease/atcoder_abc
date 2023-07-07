// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t
#define ld __double2

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    ll a, b;
    cin >> a >> b;
    ll ans = 0;
    if (a < b) swap(a, b);
    while (b > 0) {
        ans += a / b;
        a %= b;
        swap(a, b);
    }
    cout << ans - 1 << endl;
    return 0;
}
