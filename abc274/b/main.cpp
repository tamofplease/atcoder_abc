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
    int h, w;
    cin >> h >> w;
    vector<int> ans(w, 0);
    rep(i, h) {
        string s;
        cin >> s;
        rep(j, w) { ans[j] += (s[j] == '#'); }
    }
    cout << ans[0];
    Rep(i, w - 1) cout << " " << ans[i];
    cout << endl;
    return 0;
}
