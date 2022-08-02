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

const int MOD = 998244353;

using mint = modint998244353;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    mint ans = 0;
    Rep(i, n) {
        vector<vector<vector<mint>>> dp(
            n + 1, vector<vector<mint>>(i + 1, vector<mint>(i, 0)));  /// j子選択して、kあまる通り数
        dp[0][0][0] = 1;
        rep(j, n) {
            rep(k, i + 1) {
                rep(l, i) {
                    dp[j + 1][k][l] += dp[j][k][l];
                    if (k != i) dp[j + 1][k + 1][(l + a[j]) % i] += dp[j][k][l];
                }
            }
        }
        ans += dp[n][i][0];
    }
    cout << ans.val() << endl;
    return 0;
}
