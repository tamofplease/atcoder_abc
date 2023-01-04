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
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> v;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    ll ans = INT64_MAX;
    vector<vector<ll>> vertical(n, vector<ll>(n, 0)), horizontal(n, vector<ll>(n, 0));
    rep(r, n) rep(l, n) {
        ll right = v[r][0], left = v[l][0];
        rep(i, n) {
            if (left <= v[i][0] && v[i][0] <= right) {
                horizontal[l][r] |= (1LL << i);
            }
        }
    }
    rep(t, n) rep(b, n) {
        ll top = v[t][1], bottom = v[b][1];
        rep(i, n) {
            if (bottom <= v[i][1] && v[i][1] <= top) {
                vertical[b][t] |= (1LL << i);
            }
        }
    }

    rep(r, n) rep(l, n) {
        ll hor = horizontal[l][r];
        rep(t, n) rep(b, n) {
            ll ver = vertical[b][t];
            if (__builtin_popcountll(ver & hor) >= k) {
                ans = min(ans, (v[r][0] - v[l][0]) * (v[t][1] - v[b][1]));
            }
        }
    }
    cout << ans << endl;

    return 0;
}
