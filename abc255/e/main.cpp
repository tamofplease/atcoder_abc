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
    int n, m;
    cin >> n >> m;
    vector<ll> s(n - 1), x(m), a(n, 0);
    rep(i, n - 1) cin >> s[i];
    rep(i, m) cin >> x[i];
    a[0] = 0;
    Rep(i, n - 1) { a[i] = s[i - 1] - a[i - 1]; }
    unordered_map<ll, int> ma;
    int ans = 0;
    rep(i, n) {
        rep(j, m) {
            ll df = (i % 2 ? -1 : 1) * (a[i] - x[j]);
            ma[df]++;
            ans = max(ma[df], ans);
        }
    }
    cout << ans << endl;

    return 0;
}
