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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    Rep(i, m) {
        int l, r;
        cin >> l >> r;
        Rep(j, l) dp[j][r]++;
    }
    rep(i, n) rep(j, n) dp[i][j + 1] += dp[i][j];
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << dp[l][r] << endl;
    }
    return 0;
}
