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
    int h, w;
    cin >> h >> w;
    vector<string> a(h);
    map<char, int> ma = {{'+', 1}, {'-', -1}};
    vector<vector<int>> dp(h, vector<int>(w, 0));
    for (auto& ref : a) cin >> ref;
    for (int r = h - 1; r >= 0; r--) {
        for (int c = w - 1; c >= 0; c--) {
            bool isTakahashiTurn = (r + c) % 2;
            if (c == w - 1 && r == h - 1) continue;
            if (r == h - 1) {
                dp[r][c] = dp[r][c + 1] + (isTakahashiTurn ? 1 : -1) * ma[a[r][c + 1]];
                continue;
            }
            if (c == w - 1) {
                dp[r][c] = dp[r + 1][c] + (isTakahashiTurn ? 1 : -1) * ma[a[r + 1][c]];
                continue;
            }
            if (isTakahashiTurn) {
                dp[r][c] = max(dp[r][c + 1] + ma[a[r][c + 1]], dp[r + 1][c] + ma[a[r + 1][c]]);
            } else {
                dp[r][c] = min(dp[r][c + 1] - ma[a[r][c + 1]], dp[r + 1][c] - ma[a[r + 1][c]]);
            }
        }
    }
    if (dp[0][0] == 0) {
        puts("Draw");
    } else if (dp[0][0] > 0) {
        puts("Aoki");
    } else {
        puts("Takahashi");
    }
    return 0;
}
