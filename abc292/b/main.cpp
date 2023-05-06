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
    int n, q;
    cin >> n >> q;
    vector<int> memo(n, 0);
    rep(i, q) {
        int x, e;
        cin >> e >> x, x--;
        if (e != 3) {
            memo[x] += e;
            continue;
        }
        if (memo[x] >= 2) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
