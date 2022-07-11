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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<ll> b(n + 1);
    for (auto &ref : a)
        cin >> ref;
    sort(ALL(a));
    b[0] = 0;
    Rep(i, n) { b[i] = b[i - 1] + a[i - 1]; }
    rep(i, q) {
        ll x;
        cin >> x;
        auto it = lower_bound(ALL(a), x);
        int lIdx = it - a.begin();
        cout << abs(b[lIdx] - x * lIdx) + abs((b[n] - b[lIdx]) - x * (n - lIdx))
             << endl;
    }
    return 0;
}
