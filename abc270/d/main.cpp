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

int dp(const vector<int>& v, int remain, bool turn);

int ma = 0, mi = 0;
unordered_map<int, int> memo;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for (auto& ref : v) cin >> ref;
    vector<int> dp(n + 1, 0);
    rep(i, n + 1) rep(j, k) {
        if (i >= v[j]) dp[i] = max(dp[i], v[j] + (i - v[j]) - dp[i - v[j]]);
    }
    cout << dp[n] << endl;

    return 0;
}
