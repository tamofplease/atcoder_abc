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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll& ref : a) {
        cin >> ref;
    }
    vector<ll> ones, zeros;
    for (ll i = 0; i < 42; i++) {
        int one = 0, zero = 0;
        for (ll aa : a) (((aa >> i) & 1LL) ? one : zero)++;
        ones.push_back(one);
        zeros.push_back(zero);
    }

    // dp[i][0] -> same, dp[i][1] -> smaller
    ll same = 0, smaller = 0;
    for (ll i = 40; i >= 0; i--) {
        ll one_gain = (1LL << i) * zeros[i], zero_gain = (1LL << i) * ones[i];
        ll nxt_same = 0, nxt_smaller = 0;
        if (k & (1LL << i)) {
            nxt_same = same + one_gain;
            if (smaller != 0) {
                nxt_smaller = max(smaller + max(zero_gain, one_gain), same + zero_gain);
            } else {
                nxt_smaller = max(same, smaller + zero_gain);
            }
        } else {
            nxt_same = same + zero_gain;
            if (smaller != 0) nxt_smaller = smaller + max(zero_gain, one_gain);
        }
        smaller = nxt_smaller, same = nxt_same;
    }
    cout << max(smaller, same) << endl;
    return 0;
}
