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

int grid[301][301][301];
int main() {
    int H, W, n, h, w;
    cin >> H >> W >> n >> h >> w;
    int base[301];
    memset(base, 0, 301 * 4);
    vector<vector<int>> a(H + 1, vector<int>(W + 1));
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++) {
            cin >> a[i][j];
            base[a[i][j]]++;
        }

    memset(grid, 0, 301 * 301 * 301 * 4);

    for (int i = 1; i <= H; i++) {
        memcpy(grid[i][1], grid[i - 1][1], 301 * 4);
        grid[i][1][a[i][1]]++;
    }

    for (int j = 1; j <= W; j++) {
        memcpy(grid[1][j], grid[1][j - 1], 301 * 4);
        grid[1][j][a[1][j]]++;
    }

    for (int i = 2; i <= H; i++) {
        for (int j = 2; j <= W; j++) {
            for (int k = 1; k <= 300; k++) {
                grid[i][j][k] = grid[i - 1][j][k] + grid[i][j - 1][k] - grid[i - 1][j - 1][k];
            }
            grid[i][j][a[i][j]]++;
        }
    }

    for (int i = 0; i <= H - h; i++) {
        for (int j = 0; j <= W - w; j++) {
            int cur = 0;
            for (int k = 1; k <= 300; k++)
                if (base[k] != grid[i + h][j + w][k] + grid[i][j][k] - grid[i][j + w][k] - grid[i + h][j][k]) cur++;
            cout << cur << " ";
        }
        cout << endl;
    }

    return 0;
}
