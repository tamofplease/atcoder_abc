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
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n);
    for (auto& ref : a) cin >> ref;
    for (auto& ref : b) cin >> ref;
    ll ans = 0;
    rep(i, n) {
        if (a[i] > b[i]) {
            ans += b[i];
            continue;
        }
        if (a[i] <= b[i]) {
            ans += min(b[i], a[i] + a[i + 1]);
            a[i + 1] = max(0, a[i] + a[i + 1] - b[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
