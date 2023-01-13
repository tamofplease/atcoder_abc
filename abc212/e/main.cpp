// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define rRep(i, n) for (int i = n; i >= 1; i--)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;
// using mint = modint1000000007;
using mint = modint998244353;

const int MOD = 1000000007;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> from(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        if (u > v) swap(u, v);
        from[u].push_back(v);
    }
    vector dp(k + 1, vector<mint>(n, 0));
    dp[0][0] = 1;
    mint sum = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] -= dp[i - 1][j];
            for (int f : from[j]) {
                dp[i][j] -= dp[i - 1][f];
                dp[i][f] -= dp[i - 1][j];
            }
        }
        rep(j, n) dp[i][j] += sum;
        sum = accumulate(ALL(dp[i]), (mint)0);
    }
    cout << dp[k][0].val() << endl;
    return 0;
}
