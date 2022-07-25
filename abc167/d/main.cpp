// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<vector<int>> dp(65, vector<int>(n, 0));
    rep(i, n) cin >> dp[0][i], dp[0][i]--;
    rep(i, 64) {
        rep(j, n) { dp[i + 1][j] = dp[i][dp[i][j]]; }
    }
    string b = "";
    while (k > 0) {
        b += to_string(k % 2);
        k /= 2;
    }
    int m = b.length();
    int cur = 0;
    for (int i = 0; i < m; i++) {
        char c = b[i];
        if (c == '1') {
            cur = dp[i][cur];
        }
    }
    cout << cur + 1 << endl;
    return 0;
}