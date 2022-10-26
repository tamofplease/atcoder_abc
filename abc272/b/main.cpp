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
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> memo(n, vector<bool>(n, false));
    rep(i, n) memo[i][i] = true;
    rep(i, m) {
        int k;
        cin >> k;
        vector<int> v(k);
        for (int& ref : v) cin >> ref, ref--;
        rep(i, k) rep(j, i) {
            memo[v[i]][v[j]] = true;
            memo[v[j]][v[i]] = true;
        }
    }
    bool valid = true;
    rep(i, n) rep(j, n) if (!memo[i][j]) valid = false;
    valid ? puts("Yes") : puts("No");
    return 0;
}
