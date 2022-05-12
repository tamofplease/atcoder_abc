// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    int h, n;
    cin >> h >> n;
    vector<pair<int, int>> t(n);
    int m = 0;

    rep(i, n) {
        cin >> t[i].first >> t[i].second;
        m = max(m, t[i].first);
    }

    int s = h + m;
    vector<int> dp(s+1, 100000001);

    dp[0] = 0;
    Rep(i, n) {
        pair<int, int> cur = t[i-1];
        for (int j = 0 ; j < s ; j++) {
            if (j - cur.first >= 0) {
                dp[j] = min(dp[j - cur.first] + cur.second, dp[j]);
            }
        }
        for (int j = s - 1 ; j >= 0 ; j--) {
            dp[j] = min(dp[j], dp[j+1]);
        }
    }

    cout << dp[h] << endl;

    return 0;
}
