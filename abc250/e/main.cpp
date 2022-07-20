// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) { cin >> a[i]; }
    rep(i, n) cin >> b[i];

    int ia = 0, ib = -1;
    set<pair<int, int>> ans;
    set<int> sa, sb;

    int q;
    cin >> q;
    rep(i, q) {
        int x, y;
        cin >> x >> y, x--, y--;
    }
    return 0;
}
