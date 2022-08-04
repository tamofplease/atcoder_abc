// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int h, n;
    cin >> h >> n;
    vector<P> v(n);
    rep(i, n) { cin >> v[i].first >> v[i].second; }

    // i番目までみて、体力をj減らす際に消費する体力の最小値
    vector<vector<int>> dp(n + 1, vector<int>(h + 1, INT32_MAX));
    dp[0][0] = 0;
    rep(i, n) {
        dp[i + 1][0] = 0;
        Rep(j, h) {
            if (dp[i][j] != INT32_MAX) dp[i + 1][j] = dp[i][j];
            if (dp[i + 1][max(j - v[i].first, 0)] != INT32_MAX)
                chmin(dp[i + 1][j], dp[i + 1][max(0, j - v[i].first)] + v[i].second);
        }
        for (int j = h - 1; j >= 0; j--) {
            chmin(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }
    // rep(i, n) {
    // rep(j, 1 + h) cout << dp[i][j] << " ";
    // cout << endl;
    // }
    cout << dp[n][h] << endl;

    return 0;
}
