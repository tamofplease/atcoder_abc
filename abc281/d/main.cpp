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

ll dp[101][101][101];
int main() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (auto& ref : a) cin >> ref;
    rep(i, 101) rep(j, 101) rep(k, 101) dp[i][j][k] = -1;
    dp[0][0][0] = 0;
    rep(i, n) rep(j, k + 1) rep(l, d) {
        if (dp[i][j][l] != -1) chmax(dp[i + 1][j][l], dp[i][j][l]);
        if (dp[i][j][l] != -1) {
            ll sum = dp[i][j][l] + a[i];
            chmax(dp[i + 1][j + 1][sum % d], sum);
        }
    }
    cout << dp[n][k][0] << endl;

    return 0;
}
