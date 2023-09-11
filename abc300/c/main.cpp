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
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];
    vector<int> ans(min(h, w), 0);
    auto cnt_cross = [&](int x, int y) -> int {
        int r = x + 1, l = x - 1, t = y - 1, b = y + 1;
        int cnt = 0;
        while (r < w && l >= 0 && t >= 0 && b < h) {
            vector<int> xxx = {r, l};
            vector<int> yyy = {b, t};
            for (int xx : xxx) {
                for (int yy : yyy) {
                    if (grid[yy][xx] != '#') return cnt;
                }
            }
            r++, l--, t--, b++;
            cnt++;
        }
        return cnt;
    };

    rep(i, h) {
        rep(j, w) {
            if (grid[i][j] == '#') {
                int res = cnt_cross(j, i);
                if (res == 0) continue;
                // cout << i << " " << j << endl;
                ans[res - 1]++;
            }
        }
    }
    cout << ans[0];
    rep(i, min(h, w) - 1) { cout << " " << ans[i + 1]; }
    cout << endl;
    return 0;
}
