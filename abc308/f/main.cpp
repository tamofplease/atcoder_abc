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
    int n, m;
    cin >> n >> m;
    multiset<int> p;
    vector<pair<int, int>> coupons(m);
    ll ans = 0;
    rep(i, n) {
        int pp;
        cin >> pp;
        p.insert(pp);
        ans += pp;
    }
    rep(i, m) cin >> coupons[i].second;
    rep(i, m) cin >> coupons[i].first;
    sort(coupons.rbegin(), coupons.rend());
    for (auto [discount, lower] : coupons) {
        auto it = p.lower_bound(lower);
        if (it == p.end()) continue;
        ans -= discount;
        auto iter = p.find(*it);
        p.erase(iter);
    }
    cout << ans << endl;
    return 0;
}
