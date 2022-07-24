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
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    if (l <= L && R <= r) {
        cout << R - L << endl;
    } else if (L <= l && r <= R) {
        cout << r - l << endl;
    } else if (R <= l || r <= L) {
        cout << 0 << endl;
    } else if (L <= r && r <= R) {
        cout << r - L << endl;
    } else {
        cout << R - l << endl;
    }

    return 0;
}
