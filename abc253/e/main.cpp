// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));
    /// i番目の要素がjになる通り数。
    Rep(i, m) {
        dp[1][i] = 1;
    }
    const int MOD = 998244353;
    for (int i = 2 ; i <= n ; i++) {
        Rep(j, m-1) {
            dp[i-1][j+1] += dp[i-1][j];
            dp[i-1][j+1] %= MOD;
        }
        Rep(j, m) {
            if (k == 0) {
                dp[i][j] = dp[i-1][m];
                continue;
            }
            if (j + k <= m) {
                dp[i][j] += (MOD + (dp[i-1][m] - dp[i-1][j+k-1])) % MOD;
                dp[i][j] %= MOD;
            }
            if (j - k > 0) {
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= MOD;
            }
        }
    }
    ll ans = 0;
    Rep(i, m) {
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << (MOD + ans) % MOD << endl;
    return 0;
}
