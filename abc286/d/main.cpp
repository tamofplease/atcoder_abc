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
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    rep(i, n) cin >> v[i].first >> v[i].second;
    vector<bool> dp(x + 1, false);
    dp[0] = true;
    for (auto [v, m] : v) {
        for (int i = x; i >= 0; i--) {
            if (!dp[i]) continue;
            for (int j = 1; j <= m; j++) {
                if (i + j * v <= x) dp[i + j * v] = true;
            }
        }
    }
    if (dp[x])
        puts("Yes");
    else
        puts("No");

    return 0;
}
