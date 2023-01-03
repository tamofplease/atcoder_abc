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
// using mint = modint1000000007;
using mint = modint998244353;

const int MOD = 1000000007;

int op(int a, int b) { return a | b; }

int e() { return 0; }

int main() {
    int n, q;
    string s;
    cin >> n >> s >> q;
    segtree<int, op, e> seg(n);
    for (int i = 0; i < n; i++) {
        seg.set(i, 1 << (s[i] - 'a'));
    }
    rep(j, q) {
        int t, i;
        cin >> t >> i, i--;
        if (t == 1) {
            char c;
            cin >> c;
            seg.set(i, 1 << (c - 'a'));
        }
        if (t == 2) {
            int r;
            cin >> r;
            cout << __builtin_popcount(seg.prod(i, r)) << endl;
        }
    }
    return 0;
}
