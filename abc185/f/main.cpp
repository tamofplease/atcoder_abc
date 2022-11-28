// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/segtree>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int op(const int a, const int b) { return a ^ b; }

int e() { return 0; }

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    segtree<int, op, e> seg(a);

    rep(i, q) {
        int t, x, y;
        cin >> t >> x >> y, x--;
        if (t == 1) {
            seg.set(x, seg.get(x) ^ y);
            continue;
        }
        cout << seg.prod(x, y) << endl;
    }
    return 0;
}
