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
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int ans = 0;
    vector<vector<bool>> grid(h, vector<bool>(w, false));
    auto dfs = [&](auto f, int idx, int remain_two) -> void {
        if (remain_two == 0) {
            ans++;
            return;
        }
        for (int i = idx + 1; i < h * w; i++) {
            int nw = i % w, nh = i / w;
            if (grid[nh][nw]) continue;
            grid[nh][nw] = true;
            if (nh + 1 < h && !grid[nh + 1][nw]) {
                grid[nh + 1][nw] = true;
                f(f, i, remain_two - 1);
                grid[nh + 1][nw] = false;
            }
            if (nw + 1 < w && !grid[nh][nw + 1]) {
                grid[nh][nw + 1] = true;
                f(f, i, remain_two - 1);
                grid[nh][nw + 1] = false;
            }
            grid[nh][nw] = false;
        }
    };
    dfs(dfs, -1, a);
    cout << ans << endl;
    return 0;
}