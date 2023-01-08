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
    ll n;
    cin >> n;
    if (n == 2) {
        cout << 1 << endl;
        return 0;
    }
    set<ll> candidates = {n - 1, n};
    for (ll i = 2; i * i <= n; i++) {
        if (n % i != 0) continue;
        candidates.insert(i);
        candidates.insert(n / i);
    }
    for (ll i = 2; i * i <= n - 1; i++) {
        if ((n - 1) % i != 0) continue;
        candidates.insert(i);
        candidates.insert((n - 1) / i);
    }
    int ans = 0;
    for (ll c : candidates) {
        ll m = n;
        while (m % c == 0) m /= c;
        if (m % c == 1) ans++;
    }
    cout << ans << endl;
    return 0;
}
