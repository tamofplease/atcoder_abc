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
    int n, t;
    cin >> n >> t;
    vector<int> a, b;
    for (int i = 0; i < n / 2; i++) {
        int aa;
        cin >> aa;
        a.push_back(aa);
    }
    for (int i = n / 2; i < n; i++) {
        int bb;
        cin >> bb;
        b.push_back(bb);
    }
    vector<ll> a_all, b_all;
    for (int i = 0; i < (1 << a.size()); i++) {
        a_all.push_back(0);
        for (int bit = 0; bit < (int)a.size(); bit++) {
            if (i & (1 << bit)) a_all.back() += a[bit];
        }
    }
    for (int i = 0; i < (1 << b.size()); i++) {
        b_all.push_back(0);
        for (int bit = 0; bit < (int)b.size(); bit++)
            if (i & (1 << bit)) b_all.back() += b[bit];
    }

    sort(a_all.begin(), a_all.end());
    sort(b_all.begin(), b_all.end());
    ll ans = 0;
    for (ll b_l : b_all) {
        auto it = upper_bound(a_all.begin(), a_all.end(), t - b_l);
        if (it == a_all.begin()) continue;
        it--;
        ans = max(ans, b_l + (*it));
    }
    cout << ans << endl;

    return 0;
}
