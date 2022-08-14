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

bool isBlack(int r, int c);

int main() {
    int r, c;
    cin >> r >> c;
    string black = "black", white = "white";
    vector<vector<char>> grid(15, vector<char>(15, '.'));
    rep(i, 15) for (int j = min(i, 15 - i); j < max(i, 15 - i); j++) {
        if (i % 2) grid[i][j] = '#';
    }
    rep(i, 15) for (int j = min(i, 15 - i); j < max(i + 1, 15 - i); j++) {
        if (i % 2) grid[j][i] = '#';
    }
    if (grid[r - 1][c - 1] == '.')
        cout << black;
    else
        cout << white;
    cout << endl;
}
