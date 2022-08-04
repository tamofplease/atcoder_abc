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

const int MOD = 1000000007;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));
    dp[0][0] = 1;
    dp[0][2] = 1;
    rep(i, n) {
        int c = s[i] - '0';
        int a = min(dp[i][0], dp[i][2]);
        int b = min(dp[i][1], dp[i][3]);
        dp[i + 1][0] = a + 10 - (c + 1);
        dp[i + 1][1] = a + 10 - c;
        dp[i + 1][2] = b + c + 1;
        dp[i + 1][3] = b + c;
    }
    cout << min(dp[n][1], dp[n][3]) << endl;
    return 0;
}
