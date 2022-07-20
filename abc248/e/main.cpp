// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t


int NCR(int n, int r) {
    if (r == 0) return 1;
    if (r > n / 2) return NCR(n, n - r);

    ll res = 1;

    for (int k = 1; k <= r; ++k) {
        res *= n - k + 1;
        res /= k;
    }
    return res;
}

class Coordinate {
public:
    ll dx, dy, top;
    Coordinate(ll dx, ll dy, ll top) : dx(dx), dy(dy), top(top) {}

    bool operator<(const Coordinate& c) const {
        if (dx != c.dx) {
            return dx < c.dx;
        }
        if (dy != c.dy) {
            return dy < c.dy;
        }
        return top < c.top;
    }
};

bool isSame(Coordinate d1, Coordinate d2) {
    bool isSlopeIsSame = d1.dy * d2.dx == d1.dx * d2.dy;
    bool isInterceptIsSame = d1.top * d2.dx == d1.dx * d2.top;
    return isSlopeIsSame && isInterceptIsSame;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<pair<ll, ll>> p;
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        p.emplace_back(x, y);
    }
    if (k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }
    vector<int> vertical, horizontal;
    sort(p.begin(), p.end());
    vector<vector<int>> checked(n, vector<int>(n, false));
    rep(i, n) {
        checked[i][i] = true;
    }

    rep(i, n) {
        auto [x1, y1] = p[i];
        rep(j, i) {
            auto [x2, y2] = p[j];
            if (x1 == x2) {
                vertical[x1]++;
                checked[i][j] = true;
                checked[j][i] = true;
                continue;
            }
            if (y1 == y2) {
                horizontal[y1]++;
                checked[i][j] = true;
                checked[j][i] = true;
                continue;
            }

        }
    }


    return 0;
}
