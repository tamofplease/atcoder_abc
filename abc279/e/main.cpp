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
    int n, m;
    cin >> n >> m;
    vector<int> memo(n + 1), ma(m, 1), mapper(m + 1);
    for (int i = 1; i <= n; i++) memo[i] = i;
    rep(i, m) {
        int a;
        cin >> a;
        int from = memo[a], to = memo[a + 1];
        if (from == 1 || to == 1) ma[i] = to ^ 1 ^ from;
        swap(memo[a], memo[a + 1]);
    }
    for (int i = 1; i <= n; i++) {
        mapper[memo[i]] = i;
    }
    for (const int mmm : ma) {
        cout << mapper[mmm] << endl;
    }

    return 0;
}
