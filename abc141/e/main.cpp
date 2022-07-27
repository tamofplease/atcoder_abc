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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    int ans = 0;
    Rep(i, n) Rep(j, i) {
        if (s[i - 1] == s[j - 1] && i - j > dp[i - 1][j - 1]) {
            dp[i][j] = dp[i - 1][j - 1] + 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
