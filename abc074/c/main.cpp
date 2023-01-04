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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans_sugar = 0, ans_sugar_water = 0;
    set<pair<int, int>> been;
    auto dfs1 = [&](auto dfs, int water, int sugar) -> void {
        int sugar_water = water + sugar;
        if (sugar_water > f || been.count({water, sugar})) return;
        if (e * sugar_water >= sugar * (100 + e) && (ans_sugar * sugar_water) <= (sugar * ans_sugar_water)) {
            ans_sugar = sugar;
            ans_sugar_water = sugar_water;
        }
        been.insert({water, sugar});
        dfs(dfs, water + 100 * a, sugar);
        dfs(dfs, water + 100 * b, sugar);
        dfs(dfs, water, sugar + c);
        dfs(dfs, water, sugar + d);
    };
    dfs1(dfs1, 0, 0);
    cout << ans_sugar_water << " " << ans_sugar << endl;

    return 0;
}
