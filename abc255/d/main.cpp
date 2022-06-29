// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), x(q);
    for (auto &ref : a)
        cin >> ref;
    sort(a.begin(), a.end());

    for (auto &ref : x)
        cin >> ref;

    vector<ll> s(n + 1, 0);
    Rep(i, n) { s[i] = s[i - 1] + a[i - 1]; }
    rep(i, q) {
        auto it = lower_bound(a.begin(), a.end(), x[i]);
        ll k = it - a.begin();
        ll ans = 0;
        ans += k * x[i] - s[k];
        ans += (s[n] - s[k]) - (n - k) * x[i];
        cout << ans << endl;
    }
    return 0;
}
