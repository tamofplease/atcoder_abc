// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    ll n;
    cin >> n;
    map<int, vector<int>> ma;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        ma[a[i]].push_back(i);
    }
    ll ans = (n * (n - 1) * (n - 2)) / 6;
    // ma[i] = {} : i has occured in vectors positioh
    for (auto it : ma) {
        ll m = it.second.size();
        if (m == 1) {
            continue;
        } else if (m == 2) {
            ans -= (n - m);
        } else {
            // choose two same number.
            ans -= m * (m-1) * (n - m) / 2;

            // choose three same number;
            ans -= (m * (m - 1) * (m - 2)) / 6;
        }
    }
    cout << ans << endl;
    return 0;
}
