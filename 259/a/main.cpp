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
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    if (m >= x) {
        cout << t << endl;
        return 0;
    }
    cout << t - (x - m) * d << endl;
    return 0;
}
