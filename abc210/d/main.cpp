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
    ll h, w, c;
    cin >> h >> w >> c;
    vector<vector<ll>> a(h, vector<ll>(w, 0));
    ll one = INT64_MAX, two = INT64_MAX;
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        if (a[i][j] < one)
            one = a[i][j];
        else if (a[i][j] < two)
            two = a[i][j];
    }
    if (c == 0) {
        cout << one + two << endl;
        return 0;
    }
    ll ans = INT64_MAX;
    rep(_, 2) {
        vector<vector<ll>> dp(h, vector<ll>(w, INT64_MAX));
        rep(i, h) rep(j, w) {
            if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            dp[i][j] = min(dp[i][j], a[i][j] - c * (i + j));
        }
        // for (vector<ll> d : dp) {
        //     for (ll dd : d) cout << dd << " ";
        //     cout << endl;
        // }
        rep(i, h) rep(j, w) {
            if (i > 0) ans = min(ans, a[i][j] + c * (i + j) + dp[i - 1][j]);
            if (j > 0) ans = min(ans, a[i][j] + c * (i + j) + dp[i][j - 1]);
            if (j > 0 && i > 0) ans = min(ans, a[i][j] + c * (i + j) + dp[i - 1][j - 1]);
        }
        reverse(ALL(a));
    }
    cout << ans << endl;

    return 0;
}
