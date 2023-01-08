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
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> v(r, vector<int>(c, 0));
    rep(i, k) {
        int rr, cc, vv;
        cin >> rr >> cc >> vv, cc--, rr--;
        v[rr][cc] = vv;
    }
    vector<vector<vector<ll>>> dp(r + 1, vector<vector<ll>>(c + 1, vector<ll>(4, 0LL)));
    rep(rr, r) rep(cc, c) {
        chmax(dp[rr][cc + 1][0], dp[rr][cc][0]);
        chmax(dp[rr + 1][cc][0], dp[rr][cc][3]);
        for (int i = 0; i < 3; i++) {
            chmax(dp[rr][cc + 1][i + 1], max(dp[rr][cc][i + 1], dp[rr][cc][i] + v[rr][cc]));
            chmax(dp[rr + 1][cc][0], max(dp[rr + 1][cc][0], dp[rr][cc][i] + v[rr][cc]));
        }
    }
    ll ans = v[0][0];
    Rep(rr, r) Rep(cc, c) { rep(i, 4) ans = max(ans, dp[rr][cc][i]); }
    cout << ans << endl;
    return 0;
}
