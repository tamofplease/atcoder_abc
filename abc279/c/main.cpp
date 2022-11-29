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
    int rows, cols;
    cin >> rows >> cols;
    vector<string> s(rows), t(rows);
    vector<vector<char>> sv(cols, vector<char>(rows)), tv(cols, vector<char>(rows));
    rep(i, rows) cin >> s[i];
    rep(i, rows) cin >> t[i];
    rep(i, rows) {
        rep(j, cols) {
            sv[j][i] = s[i][j];
            tv[j][i] = t[i][j];
        }
    }
    sort(sv.begin(), sv.end());
    sort(tv.begin(), tv.end());
    rep(i, cols) {
        if (sv[i] != tv[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");

    return 0;
}
