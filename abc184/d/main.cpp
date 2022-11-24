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
    int a, b, c;
    cin >> a >> b >> c;
    double dp[101][101][101];
    memset(dp, 0, sizeof(dp));
    dp[a][b][c] = 1;
    double ans = 0;
    for (int i = a; i < 101; i++) {
        for (int j = b; j < 101; j++) {
            for (int k = c; k < 101; k++) {
                if (i == a && j == b && k == c) {
                    continue;
                }
                if (i != a && j != 100 && k != 100) dp[i][j][k] += dp[i - 1][j][k] * (double(i - 1) / (i + j + k - 1));
                if (j != b && i != 100 && k != 100) dp[i][j][k] += dp[i][j - 1][k] * (double(j - 1) / (i + j + k - 1));
                if (k != c && i != 100 && j != 100) dp[i][j][k] += dp[i][j][k - 1] * (double(k - 1) / (i + j + k - 1));
                ans += dp[i][j][k];
            }
        }
    }
    printf("%.9f\n", ans);

    return 0;
}
