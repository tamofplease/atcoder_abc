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
    vector<int> x(m);
    for (auto& ref : x) cin >> ref;
    sort(ALL(x));
    vector<int> diff(m - 1, 0);
    rep(i, m - 1) { diff[i] = x[i + 1] - x[i]; }
    sort(ALL(diff), greater<int>());
    int base = x[m - 1] - x[0];
    rep(i, min(n - 1, m - 1)) { base -= diff[i]; }
    cout << base << endl;

    return 0;
}
