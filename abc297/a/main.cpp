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
    int n, d;
    cin >> n >> d;
    int t;
    cin >> t;
    rep(i, n - 1) {
        int cur = t;
        cin >> t;
        if (t - cur <= d) {
            cout << t << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
