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
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> move;
    for (int i = 0; i * i <= m; i++) {
        int j = sqrt(m - i * i);
        if (i * i + j * j != m) continue;
        move.emplace(i, j);
        move.emplace(-i, j);
        move.emplace(i, -j);
        move.emplace(-i, -j);
    }
    vector<vector<int>> ans(n, vector<int>(n, -1));
    ans[0][0] = 0;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    while (q.size()) {
        const auto [r, c] = q.front();
        q.pop();
        for (pair<int, int> m : move) {
            int nr = m.first + r, nc = m.second + c;
            if (0 <= nr && nr < n && 0 <= nc && nc < n && ans[nr][nc] == -1) {
                ans[nr][nc] = ans[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }
    for (const vector<int>& v : ans) {
        int n = v.size();
        cout << v[0];
        Rep(i, n - 1) cout << " " << v[i];
        cout << endl;
    }

    return 0;
}
