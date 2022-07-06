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
    ll n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    rep(i, n) { cin >> a[i] >> b[i]; }
    ll ans = INT64_MAX;
    ll cur = 0;
    rep(i, n) {
        cur += a[i] + b[i];
        ans = min(max((ll)0, (x - i - 1)) * b[i] + cur, ans);
    }
    cout << ans << endl;

    return 0;
}