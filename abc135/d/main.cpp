// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define Rep(i, n) for (ll i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

void show(const vector<vector<ll>>& dp) {
    for (const vector<ll> d : dp) {
        for (int a : d) {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<ll>> dp(n + 1, vector<ll>(13, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 130; j += 10) {
            if (s[i] != '?') {
                dp[i + 1][(j + s[i] - '0') % 13] += dp[i][j / 10];
                dp[i + 1][(j + s[i] - '0') % 13] %= MOD;
            } else {
                rep(k, 10) {
                    dp[i + 1][(j + k) % 13] += dp[i][j / 10];
                    dp[i + 1][(j + k) % 13] %= MOD;
                }
            }
        }

    cout << dp[n][5] << endl;

    return 0;
}
