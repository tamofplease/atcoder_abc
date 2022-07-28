// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

bool comp(const P& a, const P& b) { return a.first + a.second < b.first + b.second; }

int main() {
    int n, t;
    cin >> n >> t;
    vector<P> v(n);
    rep(i, n) { cin >> v[i].first >> v[i].second; }
    sort(ALL(v), comp);
    vector<vector<int>> dp(n + 1, vector<int>(3000 * 2 + 1, 0));
    rep(i, n) {
        rep(j, t) { dp[i + 1][j + v[i].first] = max(dp[i + 1][j + v[i].first], dp[i][j] + v[i].second); }
    }
    int ans = 0;
    rep(i, n + 1) {
        rep(j, 3000 * 2 + 1) { ans = max(ans, dp[i][j]); }
    }
    cout << ans << endl;

    return 0;
}
