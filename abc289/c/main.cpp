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
    vector<int> v(m, 0);
    rep(i, m) {
        int c;
        cin >> c;
        rep(j, c) {
            int a;
            cin >> a, a--;
            v[i] |= (1 << a);
        }
    }

    const int checker = (1 << n) - 1;
    int ans = 0;

    for (int i = 0; i < (1 << m); i++) {
        int cur = 0;
        for (int bit = 0; bit < m; bit++) {
            if ((i & (1 << bit)) == 0) continue;
            cur |= v[bit];
        }
        if (cur == checker) ans++;
    }

    cout << ans << endl;

    return 0;
}
