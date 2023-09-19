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
    for (auto &g : grid) cin >> g;

    const string base = "snuke";
    vector<int> d = {-1, 0, 1};
    rep(i, h) rep(j, w) {
        for (int dh : d) {
            for (int dw : d) {
                vector<pair<int, int>> ans;
                rep(k, 5) {
                    int ch = i + dh * k, cw = j + dw * k;
                    if (ch < 0 || h <= ch || cw < 0 || w <= cw) {
                        continue;
                    }
                    if (grid[ch][cw] != base[k]) break;
                    ans.emplace_back(ch, cw);
                }
                if (ans.size() == 5) {
                    for (auto [ch, cw] : ans) {
                        cout << ch + 1 << " " << cw + 1 << endl;
                    }
                    return 0;
                }
            }
        }
    }

    return 0;
}
