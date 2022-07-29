// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n, t;
    cin >> n >> t;
    vector<P> v(n);
    rep(i, n) { cin >> v[i].first >> v[i].second; }
    sort(ALL(v));
    vector<vector<int>> dp(n, vector<int>(t, 0));
    // select n - 1 and eq or less than t - 1
    rep(i, n - 1) {
        rep(j, t) {
            dp[i + 1][j] = dp[i][j];
            if (j - v[i].first >= 0) {
                chmax(dp[i + 1][j], dp[i][j - v[i].first] + v[i].second);
            }
        }
    }
    int ans = 0;
    rep(i, n) {
        rep(j, t) { ans = max(ans, dp[i][j] + v[i].second); }
    }
    cout << ans << endl;

    return 0;
}
