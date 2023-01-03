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
    int a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a), t(b);
    for (ll& ref : s) cin >> ref;
    for (ll& ref : t) cin >> ref;

    rep(i, q) {
        ll x;
        cin >> x;
        ll left_s = -1, right_s = -1, left_t = -1, right_t = -1;
        auto it1 = lower_bound(ALL(s), x), it2 = lower_bound(ALL(t), x);
        if (it1 != s.end()) right_s = *it1;
        if (it2 != t.end()) right_t = *it2;
        it1--, it2--;
        if (it1 >= s.begin()) left_s = *it1;
        if (it2 >= t.begin()) left_t = *it2;
        ll ans = INT64_MAX;
        if (left_s != -1 && left_t != -1) ans = min(ans, x - min(left_s, left_t));
        if (right_s != -1 && right_t != -1) ans = min(ans, max(right_s, right_t) - x);
        if (left_s != -1 && right_t != -1) ans = min(ans, right_t - left_s + min(abs(left_s - x), abs(right_t - x)));
        if (right_s != -1 && left_t != -1) ans = min(ans, right_s - left_t + min(abs(left_t - x), abs(right_s - x)));
        cout << ans << endl;
    }
    return 0;
}
