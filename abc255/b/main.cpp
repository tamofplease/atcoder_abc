// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> a(n, false);
    vector<pair<int, int>> have, dHave;
    rep(i, k) {
        int A;
        cin >> A, A--;
        a[A] = true;
    }
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        (a[i] ? have : dHave).emplace_back(x, y);
    }
    auto getDistance = [&](pair<int, int> a, pair<int, int> b) -> double {
        return sqrt(pow(abs(a.first - b.first), 2) +
                    pow(abs(a.second - b.second), 2));
    };
    double ans = 0;
    for (auto d : dHave) {
        double mi = INT32_MAX;
        for (auto h : have) {
            mi = min(getDistance(h, d), mi);
        }
        ans = max(mi, ans);
    }
    printf("%.12f\n", ans);
    return 0;
}
