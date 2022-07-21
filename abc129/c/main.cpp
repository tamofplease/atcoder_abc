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
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;
    rep(i, m) {
        int aa;
        cin >> aa;
        dp[aa] = 0;
    }
    for (int i = 2; i <= n; i++) {
        if (dp[i] == -1) {
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << endl;


    return 0;
}
