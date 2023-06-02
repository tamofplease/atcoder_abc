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

const int MOD = 1000000007;

int main() {
    ll l, n_1, n_2;
    cin >> l >> n_1 >> n_2;
    vector<pair<int, ll>> a(n_1), b(n_2);

    rep(i, n_1) { cin >> a[i].first >> a[i].second; }
    rep(i, n_2) { cin >> b[i].first >> b[i].second; }

    ll ans = 0;
    int i = 0, j = 0;
    while (i < n_1 && j < n_2) {
        ll proceed = min(a[i].second, b[j].second);
        a[i].second -= proceed;
        b[j].second -= proceed;
        if (a[i].first == b[j].first) ans += proceed;

        if (a[i].second == 0) i++;
        if (b[j].second == 0) j++;
    }
    cout << ans << endl;
    return 0;
}
