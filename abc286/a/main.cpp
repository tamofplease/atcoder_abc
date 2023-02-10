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
    int n, p, q, r, s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, q - p + 1) { swap(a[p - 1 + i], a[r - 1 + i]); }
    rep(i, n) cout << a[i] << " ";
    cout << endl;
    return 0;
}
