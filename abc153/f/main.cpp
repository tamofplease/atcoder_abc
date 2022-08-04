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

using P = pair<ll, ll>;

const int MOD = 1000000007;

int main() {
    ll n, d, a;
    cin >> n >> d >> a;
    vector<P> v(n);
    rep(i, n) cin >> v[i].first >> v[i].second;
    sort(ALL(v));
    queue<P> q;
    ll cur = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.front().first < v[i].first) {
            cur -= q.front().second;
            q.pop();
        }
        if (v[i].second > cur * a) {
            int add = ceil((double(v[i].second - (a * cur)) / a));
            ans += add;
            cur += add;
            q.emplace(v[i].first + 2 * d, add);
        }
    }
    cout << ans << endl;
    return 0;
}
