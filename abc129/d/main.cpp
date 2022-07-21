// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

void show(const vector<vector<int>>& v) {
    for (vector<int> s : v) {
        for (int c : s) {
            cout << c;
        }
        cout << endl;
    }
}

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (auto& ref : s) cin >> ref;
    vector<vector<int>> ver(h, vector<int>(w, 0)), hor(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            if (s[i][j] == '#') {
                continue;
            }
            if (j == 0) {
                hor[i][j] = 1;
                continue;
            }
            hor[i][j] = hor[i][j - 1] + 1;
        }
    }
    rep(i, h) {
        for (int j = w - 2; j >= 0; j--) {
            if (hor[i][j] != 0 && hor[i][j + 1] != 0) {
                hor[i][j] = hor[i][j + 1];
            }
        }
    }
    rep(i, h) rep(j, w) {
        if (s[i][j] == '#') {
            continue;
        }
        if (i == 0) {
            ver[i][j] = 1;
            continue;
        }
        ver[i][j] = ver[i - 1][j] + 1;
    }
    rep(j, w) {
        for (int i = h - 2; i >= 0; i--) {
            if (ver[i][j] != 0 && ver[i + 1][j] != 0) {
                ver[i][j] = ver[i + 1][j];
            }
        }
    }
    int ans = 0;
    rep(j, w) rep(i, h) {
        ans = max(ans, ver[i][j] + hor[i][j]);
    }
    cout << max(0, ans - 1) << endl;


    return 0;
}
