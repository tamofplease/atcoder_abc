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
    vector<vector<ll>> cakes;
    rep(i, n) {
        ll x, y, z;
        cin >> x >> y >> z;
        cakes.push_back({x, y, z});
    }

    ll ans = 0;
    rep(i, 8) {
        vector<vector<ll>> tmp;
        for (vector<ll>& cake : cakes) {
            vector<ll> cur = {0};
            rep(j, 3) {
                cur[0] += (ll)(i & (1 << j) ? 1 : -1) * cake[j];
                cur.push_back(cake[j]);
            }
            tmp.push_back(cur);
        }
        sort(ALL(tmp), [](const vector<ll>& a, vector<ll>& b) -> bool { return a[0] > b[0]; });
        ll a = 0, b = 0, c = 0;
        rep(j, m) { a += tmp[j][1], b += tmp[j][2], c += tmp[j][3]; }
        ans = max(ans, abs(a) + abs(b) + abs(c));
    }

    cout << ans << endl;

    return 0;
}
