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
    vector<vector<int>> a(h, vector<int>(w, 0));
    rep(i, h) rep(j, w) { cin >> a[i][j]; }
    int ans = 0;
    auto dfs = [&](auto f, int cur_h, int cur_w, set<int>& se) -> void {
        if (cur_h == h - 1 && cur_w == w - 1) {
            ans++;
            return;
        }
        if (cur_h != h - 1 && !se.count(a[cur_h + 1][cur_w])) {
            se.insert(a[cur_h + 1][cur_w]);
            f(f, cur_h + 1, cur_w, se);
            se.erase(a[cur_h + 1][cur_w]);
        }
        if (cur_w != w - 1 && !se.count(a[cur_h][cur_w + 1])) {
            se.insert(a[cur_h][cur_w + 1]);
            f(f, cur_h, cur_w + 1, se);
            se.erase(a[cur_h][cur_w + 1]);
        }
    };
    set<int> se;
    se.insert(a[0][0]);
    dfs(dfs, 0, 0, se);
    cout << ans << endl;

    return 0;
}
