// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/modint>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

using mint = atcoder::modint998244353;

using tt = tuple<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> move(3);
    for (auto& ref : move) cin >> ref.first >> ref.second;
    unordered_set<tt> obstacle;
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        obstacle.insert(make_tuple(x, y));
    }
    // dp[n][i][j] => n回の移動後に座標i, jに到達する通り数。
    unordered_map<tt, mint> dp;
    dp[make_tuple(0, 0)] = 1;
    rep(i, n) {
        unordered_map<tt, mint> new_dp;
        for (const auto [cur, val] : dp) {
            const auto [cx, cy] = cur;
            for (const auto m : move) {
                tt nxt = make_tuple(cx + m[0], cy + m[1]);
                if (obstacle.find(nxt) == obstacle.end()) new_dp[nxt] += val;
            }
        }
        dp = std::move(new_dp);
    }
    mint ans = 0;
    for (auto [_, val] : dp) {
        ans += val;
    }
    cout << ans.val() << endl;
    return 0;
}
