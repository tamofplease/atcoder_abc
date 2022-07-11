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
    int n;
    cin >> n;
    vector<ll> x(n), c(n);
    rep(i, n) { cin >> x[i], x[i]--; }
    for (auto &ref : c)
        cin >> ref;
    ll ans = 0;
    dsu d(n);
    rep(i, n) {
        if (!d.same(i, x[i])) {
            d.merge(i, x[i]);
            continue;
        }
        int cur = x[i];
        ll val = c[cur];
        while (cur != i) {
            cur = x[cur];
            val = min(val, c[cur]);
        }
        ans += val;
    }
    cout << ans << endl;

    return 0;
}
