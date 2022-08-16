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
    vector<vector<vector<int>>> dp(r + 1, vector<vector<int>>(c + 1, vector<int>(4, 0)));
    rep(rr, r) rep(cc, c) rep(i, 4) {
        if (v[rr][cc] != 0 && i != 3) {
            chmax(dp[rr + 1][cc][k + 1], dp[rr][cc][k] + v[rr][cc]);
            chmax(dp[rr][cc + 1][k + 1], dp[rr][cc][k] + v[rr][cc]);
        }
        chmax(dp[rr + 1][cc][k], dp[rr][cc][k]);
        chmax(dp[rr][cc + 1][k], dp[rr][cc][k]);
    }
    int ans = 0;
    rep(i, 3) ans = max(ans, dp[r][c][i]);
    std::cout << ans << endl;
    return 0;
}
