// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define rRep(i, n) for (int i = n; i >= 1; i--)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;
using mint = modint998244353;

const int MOD = 1000000007;

int main() {
    int n, d;
    cin >> n >> d;
    mint ans = 0;
    vector<mint> v(n + 1, 1);
    for (int i = 1; i <= n; i++) v[i] = v[i - 1] * 2;

    for (int i = 0; i <= min(d, n); i++) {
        int up = i, down = d - i;
        int df = up - down;
        if (n + df < 0 || n < down) continue;
        mint node_num = v[n + min(0, df)] - v[up];
        ans += node_num * v[down] / (up == 0 || down == 0 ? 1 : 2);
    }
    cout << ans.val() << endl;
    return 0;
}