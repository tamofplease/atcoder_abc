// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    vector<ll> y(n + 1, 0);
    rep(i, n) { cin >> x[i]; }
    rep(i, m) {
        ll c;
        cin >> c >> y[c];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    Rep(i, n) {
        rep(j, i) {
            dp[i][0] = max(dp[i - 1][j] + y[0], dp[i][0]);
            dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + x[i - 1] + y[j + 1]);
        }
    }

    ll ans = 0;
    rep(i, n + 1) { ans = max(ans, dp[n][i]); }
    cout << ans << endl;

    return 0;
}
