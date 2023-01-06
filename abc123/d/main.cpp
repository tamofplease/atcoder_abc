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
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x) cin >> a[i];
    rep(i, y) cin >> b[i];
    rep(i, z) cin >> c[i];
    vector<ll> ab(x * y, 0);
    rep(i, x) rep(j, y) { ab[i * y + j] = a[i] + b[j]; }
    sort(ALL(ab), greater<ll>());
    sort(ALL(c), greater<ll>());
    int ab_max = min(k, (int)ab.size());
    int c_max = min(k, (int)c.size());
    vector<ll> abc(ab_max * c_max, 0);
    rep(i, ab_max) rep(j, c_max) { abc[i * c_max + j] = ab[i] + c[j]; }
    sort(ALL(abc), greater<ll>());
    rep(i, k) cout << abc[i] << endl;

    return 0;
}