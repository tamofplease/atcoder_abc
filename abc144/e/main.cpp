// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

const int MOD = 1000000007;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    for (auto& ref : a) cin >> ref;
    for (auto& ref : f) cin >> ref;
    sort(a.begin(), a.end());
    sort(f.begin(), f.end(), greater());
    ll valid = 10000000000001, invalid = -1;
    auto ok = [&](ll mid) -> bool {
        int ck = k;
        ll cnt = 0;
        rep(i, n) {
            int valid = 0, invalid = a[i] + 1;
            while (invalid - valid > 1) {
                int md = (valid + invalid) / 2;
                if ((ll)md * f[i] <= mid)
                    valid = md;
                else
                    invalid = md;
            }
            cnt += a[i] - valid;
        }
        return cnt <= k;
    };

    while (valid - invalid > 1) {
        ll mid = (valid + invalid) / 2;
        if (ok(mid)) {
            valid = mid;
        } else {
            invalid = mid;
        }
    }
    cout << valid << endl;
    return 0;
}
