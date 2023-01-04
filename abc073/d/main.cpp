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
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> road(r);
    for (int& ref : road) cin >> ref, ref--;
    vector<vector<int>> costs(n, vector<int>(n, INT32_MAX / 3));
    rep(i, n) costs[i][i] = 0;
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c, a--, b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }
    for (int via = 0; via < n; via++) {
        for (int start = 0; start < n; start++) {
            for (int goal = start + 1; goal < n; goal++) {
                costs[start][goal] = min(costs[start][goal], costs[start][via] + costs[via][goal]);
                costs[goal][start] = min(costs[goal][start], costs[goal][via] + costs[via][start]);
            }
        }
    }
    int ans = INT32_MAX;
    sort(ALL(road));
    do {
        int cur = 0;
        rep(i, r - 1) { cur += costs[road[i]][road[i + 1]]; }
        ans = min(cur, ans);
    } while (next_permutation(ALL(road)));
    cout << ans << endl;

    return 0;
}
