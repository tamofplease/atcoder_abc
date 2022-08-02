// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

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

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ref : a) cin >> ref;
    ll p = 0;
    Rep(i, n) {
        if (a[i - 1] == i) p++;
    }
    ll res = 0;
    Rep(i, n) {
        if (i < a[i - 1] && a[a[i - 1] - 1] == i) {
            res++;
        }
    }
    cout << res + p * (p - 1) / 2 << endl;
    return 0;
}
