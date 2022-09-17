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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 0;
    dp[0][1] = -1000000000000000000ll;
    for (int i = 1; i <= n; i++) {
        rep(j, n + 1) {
            if (j == 0)
                dp[i][j] = 0;
            else if (j > i)
                dp[i][j] = -1000000000000000000ll;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + (ll)a[i - 1] * ll(j));
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
