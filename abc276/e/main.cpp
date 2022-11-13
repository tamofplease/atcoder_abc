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
    vector<string> c(h);
    for (string& cc : c) cin >> cc;
    pair<int, int> start;
    rep(hh, h) rep(ww, w) if (c[hh][ww] == 'S') {
        start = {hh, ww};
        break;
    }
    // cout << "start:" << start.first << " " << start.second << endl;
    const int d[5] = {0, -1, 0, 1, 0};
    auto dfs = [&](auto f, int ch, int cw, int depth) -> bool {
        rep(i, 4) {
            int nh = ch + d[i], nw = cw + d[i + 1];
            if (nh < 0 || h <= nh || nw < 0 || w <= nw || c[nh][nw] == '#') continue;
            if (c[nh][nw] == 'S' && depth > 3) return true;
            c[nh][nw] = '#';
            if (f(f, nh, nw, depth + 1)) return true;
        }
        return false;
    };

    dfs(dfs, start.first, start.second, 1) ? puts("Yes") : puts("No");

    return 0;
}
