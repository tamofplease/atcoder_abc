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
    int k;
    cin >> k;
    if (k % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }
    int cur = 7;
    int r = 1;
    vector<int> been(k + 1, false);
    while (cur % k != 0) {
        cur = cur * 10 + 7;
        cur %= k;
        if (been[cur]) {
            cout << -1 << endl;
            return 0;
        }
        been[cur] = true;
        r++;
    }
    cout << r << endl;
    return 0;
}
