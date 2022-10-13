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
    vector<string> s(10);
    rep(i, 10) cin >> s[i];
    pair<int, int> a, b;
    rep(i, 10) rep(j, 10) {
        if (s[i][j] == '#' && a.first == 0) a = {i + 1, j + 1};
    }
    for (int i = 9; i >= 0; i--)
        for (int j = 9; j >= 0; j--) {
            if (s[i][j] == '#' && b.first == 0) b = {i + 1, j + 1};
        }
    cout << a.first << " " << b.first << endl;
    cout << a.second << " " << b.second << endl;
    return 0;
}
