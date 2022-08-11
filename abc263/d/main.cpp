// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define Rep(i, n) for (ll i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    ll sum = 0;
    for (auto& ref : a) {
        cin >> ref;
        sum += ref;
    }
    vector<ll> ss(ALL(a));
    Rep(i, n - 1) ss[i] += ss[i - 1];
    vector<ll> ld(n + 1, 0), rd(n + 1, 0);
    Rep(i, n) { ld[i] = l * i - ss[i - 1]; }

    ss = a;
    for (int i = n - 2; i >= 0; i--) ss[i] += ss[i + 1];
    for (int i = n - 1; i >= 0; i--) rd[i] = r * (n - i) - ss[i];
    for (int i = n - 1; i >= 0; i--) chmin(rd[i], rd[i + 1]);
    ll ans = sum;
    rep(i, n + 1) { ans = min(ans, sum + ld[i] + rd[i]); }
    // rep(i, n + 1) cout << ld[i] << " ";
    // cout << endl;
    // rep(i, n + 1) cout << rd[i] << " ";

    cout << ans << endl;

    return 0;
}
