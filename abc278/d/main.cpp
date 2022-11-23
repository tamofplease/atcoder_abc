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
    int n;
    cin >> n;
    int latest = -1;
    ll val = -1;
    vector<pair<ll, int>> a(n, {0, -1});
    rep(i, n) cin >> a[i].first;
    int q;
    cin >> q;
    rep(i, q) {
        int qq;
        cin >> qq;
        if (qq == 1) {
            cin >> val;
            latest = i;
        }
        if (qq == 2) {
            int xi, x;
            cin >> xi >> x, xi--;
            if (a[xi].second != latest) a[xi].first = val;
            a[xi].first += x;
            a[xi].second = latest;
        }
        if (qq == 3) {
            int xi;
            cin >> xi, xi--;
            if (a[xi].second != latest) a[xi] = {val, latest};
            cout << a[xi].first << endl;
        }
    }

    return 0;
}
