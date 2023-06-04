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
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    if (x == 0) {
        puts("Yes");
        return 0;
    }
    set<ll> fnd;
    for (ll aa : a) {
        if (fnd.count(aa)) {
            puts("Yes");
            return 0;
        }
        fnd.insert(aa - x);
        fnd.insert(x + aa);
    }
    puts("No");

    return 0;
}
