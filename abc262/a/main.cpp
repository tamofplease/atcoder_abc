// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int y;
    cin >> y;
    int m = y % 4;
    if (m == 2) {
        cout << y << endl;
    } else if (m == 1) {
        cout << y + 1 << endl;
    } else if (m == 3) {
        cout << y + 3 << endl;
    } else {
        cout << y + 2 << endl;
    }
    return 0;
}
