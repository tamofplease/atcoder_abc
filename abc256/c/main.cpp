// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int summ(const vector<int> &v) {
    int su = 0;
    for (int vv : v)
        su += vv;
    return su;
}

int main() {
    vector<int> h(3, 0), w(3, 0);
    rep(i, 3) cin >> h[i];
    rep(i, 3) cin >> w[i];
    if (summ(h) != summ(w)) {
        cout << 0 << endl;
        return 0;
    }
    auto isValid = [&](const vector<vector<int>> &grid) -> bool {
        int a = w[2] - h[0] - h[1], b = h[2] - w[0] - w[1];
        if (a > 0 && b > 0 && a == b)
            return true;
        return false;
    };

    int cnt = 0;
    auto search = [&](auto f, vector<vector<int>> grid, int num) -> void {
        if (num == 4) {
            if (isValid(grid)) {
                cnt++;
            }
            return;
        }
        int ww = num % 2, hh = num / 2;
        for (int i = 1; i < min(h[hh], w[ww]); i++) {
            grid[hh][ww] = i;
            h[hh] -= i;
            w[ww] -= i;
            f(f, grid, num + 1);
            h[hh] += i;
            w[ww] += i;
            grid[hh][ww] = -1;
        }
    };
    vector<vector<int>> grid(2, vector<int>(2, -1));
    search(search, grid, 0);
    cout << cnt << endl;

    return 0;
}
