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
    int a, b;
    cin >> a >> b, a--, b--;
    vector<string> S;
    string blacks = "", whites = "";
    for (int i = 0; i < 100; i++) {
        blacks.push_back('#');
        whites.push_back('.');
    }

    for (int i = 0; i < 50; i++) S.push_back(blacks);
    for (int i = 50; i < 100; i++) S.push_back(whites);

    int row = 0, col = 0;
    while (a--) {
        S[row][col] = '.';
        col += 2;
        if (col >= 100) {
            col = 0, row += 2;
        }
    }
    row = 51, col = 0;
    while (b--) {
        S[row][col] = '#';
        col += 2;
        if (col >= 100) {
            col = 0, row += 2;
        }
    }
    cout << 100 << " " << 100 << endl;
    rep(i, 100) { cout << S[i] << endl; }

    return 0;
}
