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
    ll n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n - 1);
    rep(i, n - 1) cin >> a[i];
    map<int, int> ma;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        ma[--x] = y;
    }
    rep(i, n - 1) {
        if (ma.find(i) != ma.end()) t += ma[i];
        t -= a[i];
        if (t <= 0) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
