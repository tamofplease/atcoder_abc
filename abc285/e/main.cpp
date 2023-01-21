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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    for (int i = 0; i < (n / 2); i++) {
        a[n - i - 1] = a[i];
    }
    vector dp(n, vector<ll>(n, 0));
    auto show = [&]() -> void {
        for (vector<ll> d : dp) {
            for (ll dd : d) cout << dd << " ";
            cout << endl;
        }
    };
    for (int i = 1; i < n; i++) {
        ll ma = 0;
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + a[j - 1];
            if (n - i - 1 >= 0) chmax(dp[i][j], dp[i - 1][j - 1] + a[i]);
            ma = max(ma, dp[i - 1][j - 1]);
        }
        dp[i][0] = ma;
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) ans = max(ans, dp[i][j]);
    }
    show();
    cout << ans << endl;
    return 0;
}
