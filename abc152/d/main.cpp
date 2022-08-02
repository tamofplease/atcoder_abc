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
    int n;
    cin >> n;
    int ans = 0;
    vector<vector<int>> v(10, vector<int>(10, 0));
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        int sn = s.length();
        v[s[sn - 1] - '0'][s[0] - '0']++;
    }
    Rep(i, 9) Rep(j, 9) { ans += v[i][j] * v[j][i]; }
    cout << ans << endl;

    return 0;
}
