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

struct City {
    int x, y, z;
    City(int x, int y, int z) : x(x), y(y), z(z) {}
    int move_to(City other) { return abs(other.x - x) + abs(other.y - y) + max(0, other.z - z); }
};

int main() {
    int n;
    cin >> n;
    vector<City> cities;
    rep(i, n) {
        int x, y, z;
        cin >> x >> y >> z;
        cities.emplace_back(x, y, z);
    }
    // 今としiにいて、今までにjを回った際の最短
    vector<vector<int>> dp(n + 1, vector<int>((1 << n), INT32_MAX));
    dp[0][0] = 0;
    for (int j = 0; j < (1 << n); j++) {
        for (int to = 0; to < n; to++) {
            int nxt = j | (1 << to);
            if (nxt == j) continue;
            for (int from = 0; from < n; from++) {
                if (dp[from][j] != INT32_MAX) chmin(dp[to][nxt], dp[from][j] + cities[from].move_to(cities[to]));
            }
        }
    }
    cout << dp[0][(1 << n) - 1] << endl;

    return 0;
}
