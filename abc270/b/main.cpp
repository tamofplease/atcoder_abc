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
    int x, y, z;
    cin >> x >> y >> z;
    if (y < 0) {
        x = -x;
        y = -y;
        z = -z;
    }
    if (x < y)
        cout << abs(x) << endl;
    else {
        if (y < z)
            puts("-1");
        else
            cout << abs(z) + abs(x - z) << endl;
    }

    return 0;
}
