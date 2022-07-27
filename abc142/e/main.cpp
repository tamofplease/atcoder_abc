// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    int mb = (1 << n);
    vector<int> ma(mb, INT32_MAX);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        int se = 0;
        rep(j, b) {
            int c;
            cin >> c, c--;
            se += (1 << c);
        }
        rep(i, mb) {
            if (ma[i] == INT32_MAX) continue;
            int ns = (se | i);
            ma[ns] = min(ma[ns], a + ma[i]);
        }
        ma[se] = min(ma[se], a);
    }
    if (ma[(1 << n) - 1] == INT32_MAX) {
        cout << -1 << endl;
    } else {
        cout << ma[(1 << n) - 1] << endl;
    }
    return 0;
}
