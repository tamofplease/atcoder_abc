// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;
int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> c(n + 1, vector<ll>(n + 1, 0));
    rep(i, n + 1) {
        c[i][0] = 1;
    }
    c[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        Rep(j, i) {
            if (j == 1) {
                c[i][j] = i;
                continue;
            }
            if (j == i) {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= MOD;
        }
    }
    Rep(i, k) {
        ll ans = c[k - 1][i - 1];
        cout << (ans * c[n - k + 1][i]) % MOD << endl;
    }
    return 0;
}
