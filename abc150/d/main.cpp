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
    ll n, m, lc;
    cin >> n >> m >> lc, lc /= 2;
    vector<int> aa(n);
    aa[0] = lc;
    bool valid = true;
    Rep(i, n - 1) {
        cin >> aa[i], aa[i] /= 2;
        lc = lcm(lc, aa[i]);
        if (lc > m) {
            valid = false;
            break;
        }
    }
    if (valid && all_of(ALL(aa), [lc](const int a) -> bool { return (lc / a) % 2; })) {
        cout << ((m / lc) - 1) / 2 + 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
