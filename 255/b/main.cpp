// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

using P = pair<int, pair<int, int>>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (auto &ref : a) {
        cin >> ref;
    }
    vector<ll> x(n), y(n);
    rep(i, n) { cin >> x[i] >> y[i]; }
    vector<ll> dist(n, INT64_MAX);

    rep(i, k) {
        int from = a[i] - 1;
        rep(j, n) {
            int to = j;
            ll distance = ((x[from] - x[to]) * (x[from] - x[to])) +
                          ((y[from] - y[to]) * (y[from] - y[to]));
            dist[to] = min(dist[to], distance);
        }
    }
    rep(i, k) { dist[a[i] - 1] = 0; }

    ll ans = 0;
    rep(i, n) ans = max(dist[i], ans);
    printf("%0.10f\n", sqrt((double)ans));
    return 0;
}
