// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int main() {
    ll n, x, m;
    cin >> n >> x >> m;
    map<ll, pair<ll, ll>> num;
    num[x] = {1, x};
    ll prev = x;
    ll i;
    ll ans = x;
    ll lenLoop = 0;
    ll valLoop = 0;
    for ( i = 2 ; i <= n ; i++ ) {
        ll nxt = (prev * prev) % m;
        if (num.find(nxt) == num.end()) {
            num[nxt] = {i, nxt + num[prev].second};
            ans += nxt;
            prev = nxt;
        } else {
            valLoop = nxt + num[prev].second - num[nxt].second;
            lenLoop = i - num[nxt].first;
            ans += nxt;
            prev = nxt;
            n -= i;
            break;
        }
    }
    if (lenLoop > 0) {
        ll loopTimes = n / lenLoop;
        ans += valLoop * loopTimes;
        ll remain =  n % lenLoop;
        rep(i, remain) {
            ll nxt = (prev * prev) % m;
            ans += nxt;
            prev = nxt;
        }
    }
    cout << ans << endl;

    return 0;
}
