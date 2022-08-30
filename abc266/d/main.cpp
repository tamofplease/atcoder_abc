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
    map<pair<int, int>, ll> ma;
    rep(i, n) {
        int t, x, a;
        cin >> t >> x >> a;
        ma[{t, x}] = a;
    }
    vector<vector<ll>> dp(100001, vector<ll>(5, INT64_MIN));
    dp[0][0] = 0;
    rep(i, 100001) {
        rep(j, 5) {
            if (i != 0) chmax(dp[i][j], dp[i - 1][j]);
            if (i != 0 && j != 0) chmax(dp[i][j], dp[i - 1][j - 1]);
            if (i != 0 && j != 4) chmax(dp[i][j], dp[i - 1][j + 1]);
            if (dp[i][j] != INT64_MIN && ma.find({i, j}) != ma.end()) dp[i][j] += ma[{i, j}];
        }
    }

    ll ans = 0;
    rep(i, 5) ans = max(dp[100000][i], ans);
    cout << ans << endl;
    return 0;
}
