// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint998244353;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<mint>> dp(k + 1, vector(n + 1, mint(0)));
    mint m_inv = mint(1) / m;
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++) {
            if (j == n) {
                dp[i + 1][j] += dp[i][j];
                continue;
            }
            for (int l = 1; l <= m; l++) {
                int nx = j + l;
                if (nx > n) nx = n - (nx - n);
                dp[i + 1][nx] += dp[i][j] * m_inv;
            }
        }
    }
    cout << dp.back().back().val() << endl;

    return 0;
}
