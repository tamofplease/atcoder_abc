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
    vector<ll> a(n);
    ll sum = 0;
    map<int, ll> ma;
    rep(i, n) {
        cin >> a[i];
        sum += a[i];
        ma[a[i]] += a[i];
    }
    int prev = -1;
    ll ans = INT64_MAX;
    ll cur = sum;
    bool continueFromBegin = true;
    for (auto [k, v] : ma) {
        if (k == (prev + 1) % m) {
            cur -= v;
        } else {
            ans = min(cur, ans);
            cur = sum - v;
            continueFromBegin = false;
        }
        prev = k;
    }
    if (!continueFromBegin) {
        for (auto [k, v] : ma) {
            if (k == (prev + 1) % m) {
                cur -= v;
            } else {
                ans = min(cur, ans);
                break;
            }
            prev = k;
        }
    }
    cout << min(cur, ans) << endl;

    return 0;
}
