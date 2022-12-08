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
    vector<ll> a(n + 1, 0);
    for (int i = 0; i < n; i++) {
        ll c;
        cin >> c;
        a[i + 1] = (c + a[i]) % m;
    }
    map<ll, int> ma;
    for (int i = 0; i <= n; i++) {
        ma[a[i]]++;
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ma[a[i]]--;
        ans += ma[a[i]];
    }
    cout << ans << endl;
    return 0;
}
