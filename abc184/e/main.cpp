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

struct Data {
    int row, col, time;
    Data(int row, int col, int time) : row(row), col(col), time(time){};
};

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<string> grid;
    queue<Data> q;
    vector<unordered_set<int>> warp(26);
    vector<bool> been(rows * cols + 1, false);
    rep(r, rows) {
        string s;
        cin >> s;
        grid.push_back(s);
        for (int c = 0; c < cols; c++) {
            if (s[c] == '.' || s[c] == '#' || s[c] == 'G') continue;
            if (s[c] == 'S') {
                q.emplace(r, c, 0);
                been[r * cols + c] = true;
                continue;
            }
            warp[s[c] - 'a'].emplace(r * cols + c);
        }
    }

    int d[5] = {0, -1, 0, 1, 0};
    while (!q.empty()) {
        const auto [row, col, time] = q.front();
        q.pop();
        if (grid[row][col] == 'G') {
            cout << time << endl;
            return 0;
        }
        if (grid[row][col] != '.' && grid[row][col] != 'S') {
            for (const int idx : warp[grid[row][col] - 'a']) {
                if (been[idx]) continue;
                been[idx] = true;
                const int n_row = idx / cols, n_col = idx % cols;
                q.emplace(n_row, n_col, time + 1);
            }
            warp[grid[row][col] - 'a'] = {};
        }
        for (int i = 0; i < 4; i++) {
            int n_row = row + d[i], n_col = col + d[i + 1];
            if (n_row < 0 || rows <= n_row || n_col < 0 || cols <= n_col || been[n_row * cols + n_col] ||
                grid[n_row][n_col] == '#') {
                continue;
            }
            been[n_row * cols + n_col] = true;
            q.emplace(n_row, n_col, time + 1);
        }
    }

    cout << -1 << endl;
    return 0;
}