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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    auto ok = [&](long double mid) -> bool {
        ll res = 0;
        for (int aa : a) {
            res += ceil((long double)aa / mid) - 1;
        }
        return res <= k;
    };
    long double left = 1, right = 1000000001;
    while (right - left >= (long double)0.1) {
        long double mid = (right + left) / 2;
        (ok(mid) ? right : left) = mid;
    }
    printf("%.0Lf\n", ceil(left));
    return 0;
}
