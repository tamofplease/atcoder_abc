// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    rep(i, h) cin >> grid[i];
    int d[5] = {0, -1, 0, 1, 0};
    int ans = 0;
    rep(hs, h) rep(ws, w) {
        if (grid[hs][ws] == '#') continue;
        vector<vector<int>> board(h, vector<int>(w, -1));
        queue<pair<pair<int, int>, int>> q;
        q.push({{hs, ws}, 0});
        board[hs][ws] = 0;
        while (!q.empty()) {
            auto [cur, cost] = q.front();
            q.pop();
            auto [ch, cw] = cur;
            rep(i, 4) {
                int nh = ch + d[i], nw = cw + d[i + 1];
                if (0 <= nh && nh < h && 0 <= nw && nw < w && board[nh][nw] == -1 && grid[nh][nw] == '.') {
                    board[nh][nw] = cost + 1;
                    q.push({{nh, nw}, cost + 1});
                }
            }
        }
        rep(i, h) rep(j, w) { ans = max(ans, board[i][j]); }
    }
    cout << ans << endl;
    return 0;
}
