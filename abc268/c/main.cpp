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
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    vector<int> res(n, 0);
    rep(i, n) for (int j = -1; j <= 1; j++) res[(n + p[i] - i + j) % n]++;
    int ans = 0;
    rep(i, n) chmax(ans, res[i]);
    cout << ans << endl;
    return 0;
}
