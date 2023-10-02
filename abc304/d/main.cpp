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

ll gen(ll a, ll b) { return a * INT32_MAX + b; }

int main() {
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) { cin >> p[i] >> q[i]; }
    int aa;
    cin >> aa;
    vector<int> a(aa);
    for (int& aaa : a) cin >> aaa;
    int bb;
    cin >> bb;
    vector<int> b(bb);
    for (int& bbb : b) cin >> bbb;

    unordered_map<ll, int> piece;
    rep(i, n) {
        auto itx = lower_bound(a.begin(), a.end(), p[i]);
        auto ity = lower_bound(b.begin(), b.end(), q[i]);
        piece[gen(itx - a.begin(), ity - b.begin())]++;
    }
    int mi = INT32_MAX, ma = -1;
    for (auto [_, v] : piece) {
        mi = min(v, mi);
        ma = max(v, ma);
    }
    ll board = (aa + 1) * (bb + 1);
    if ((int)piece.size() != board) {
        cout << 0 << " " << ma << endl;
    } else {
        cout << mi << " " << ma << endl;
    }

    return 0;
}
