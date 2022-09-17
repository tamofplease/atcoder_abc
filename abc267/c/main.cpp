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
    vector<int> a(n);
    for (auto& ref : a) cin >> ref;
    ll tmp = 0, sum = 0;
    for (ll i = 0; i < m; i++) {
        tmp += (i + 1) * a[i];
        sum += a[i];
    }
    ll ans = tmp;
    for (ll i = m; i < n; i++) {
        tmp -= sum;
        tmp += (ll)a[i] * m;
        sum += (a[i] - a[i - m]);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
