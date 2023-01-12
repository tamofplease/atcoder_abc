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

size_t highestOneBitPosition(uint64_t a) {
    size_t bits = 0;
    while (a != 0) {
        ++bits;
        a >>= 1;
    };
    return bits;
}

bool multiplication_is_safe(uint64_t a, uint64_t b) {
    size_t a_bits = highestOneBitPosition(a), b_bits = highestOneBitPosition(b);
    return (a_bits + b_bits <= 64);
}

bool addition_is_safe(uint64_t a, uint64_t b) {
    size_t a_bits = highestOneBitPosition(a), b_bits = highestOneBitPosition(b);
    return (a_bits < 64 && b_bits < 64);
}

int main() {
    string x;
    int d = 0;
    cin >> x;
    reverse(ALL(x));
    ll m;
    cin >> m;
    if (x.length() == 1) {
        cout << bool(x[0] - '0' <= m) << endl;
        return 0;
    }
    for (char c : x) d = max(d, c - '0');
    const int n = x.length();
    ll sm = d, lg = m + 1;
    function<bool(ll)> check = [&](ll mid) -> bool {
        ll tmp = 1, cur = 0;
        for (int i = 0; i < n; i++) {
            int c = x[i] - '0';
            if (multiplication_is_safe(tmp, c) && addition_is_safe(cur, tmp * c))
                cur += tmp * c;
            else
                return false;
            if (multiplication_is_safe(tmp, mid))
                tmp *= mid;
            else if (i != n - 1)
                return false;
        }
        return cur <= m;
    };
    while (lg - sm > 1) {
        ll mid = (lg + sm) / 2;
        if (check(mid)) {
            sm = mid;
        } else
            lg = mid;
    }
    cout << sm - d << endl;

    return 0;
}
