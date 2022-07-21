// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    string l;
    cin >> l;
    int n = l.length();
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    dp[0][1] = 2;
    dp[0][0] = 1;
    Rep(i, n - 1) {
        dp[i][0] = dp[i - 1][0] * 3;
        dp[i][1] = dp[i - 1][1];
        if (l[i] == '1') {
            dp[i][1] += dp[i - 1][1];
            dp[i][0] += dp[i - 1][1];
        }
        dp[i][1] %= MOD;
        dp[i][0] %= MOD;
    }

    cout << (dp[n - 1][0] + dp[n - 1][1]) % MOD << endl;

    return 0;
}
