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
    int n, q, x;
    cin >> n >> q >> x;
    vector<int> w(n);
    rep(i, w) cin >> w[i];
    vector<ll> sums(n + 1, 0);
    Rep(i, n) { sums[i] += sums[i - 1] + w[i - 1] }

    return 0;
}
