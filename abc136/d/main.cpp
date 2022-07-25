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
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(33, vector<int>(n + 1, 0));
    rep(i, n) {
        if (s[i] == 'R')
            dp[0][i] = i + 1;
        else
            dp[0][i] = i - 1;
    }
    rep(p, 32) rep(i, n) { dp[p + 1][i] = dp[p][dp[p][i]]; }
    vector<int> ans(n, 0);
    rep(i, n) ans[dp[32][i]]++;
    rep(i, n) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
