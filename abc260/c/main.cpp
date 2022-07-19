// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

ll x, y;

ll changeRed(ll num, ll level);
ll changeBlue(ll num, ll level);

map<pair<ll, ll>, ll> red, blue;

ll changeBlue(ll num, ll level) {
    if (level < 2) {
        return num;
    }
    if (blue.find({ num, level }) != blue.end()) {
        return blue[{num, level}];
    }
    blue[{num, level}] =
        changeBlue(num * y, level - 1) + changeRed(num, level - 1);
    return blue[{num, level}];
}

ll changeRed(ll num, ll level) {
    if (level < 2) {
        return 0;
    }
    if (red.find({ num, level }) != red.end()) {
        return red[{num, level}];
    }
    red[{num, level}] = changeRed(num, level - 1) + changeBlue(x * num, level);
    return red[{num, level}];
}

int main() {
    ll n;
    cin >> n >> x >> y;
    ll res = changeRed(1, n);
    cout << res << endl;
    return 0;
}
