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

int twiceDist(int a, int b, int c, int d) { return (a - c) * (a - c) + (b - d) * (b - d); }

int main() {
    vector<string> s(9);
    rep(i, 9) cin >> s[i];
    int ans = 0;
    rep(a, 81) rep(b, a) rep(c, b) rep(d, c) {
        int a_r = a / 9, a_c = a % 9;
        int b_r = b / 9, b_c = b % 9;
        int c_r = c / 9, c_c = c % 9;
        int d_r = d / 9, d_c = d % 9;
        if (!(s[a_r][a_c] == '#' && s[b_r][b_c] == '#' && s[c_r][c_c] == '#' && s[d_r][d_c] == '#')) continue;
        vector<int> v;
        v.push_back(twiceDist(a_r, a_c, b_r, b_c));
        v.push_back(twiceDist(a_r, a_c, c_r, c_c));
        v.push_back(twiceDist(a_r, a_c, d_r, d_c));
        v.push_back(twiceDist(b_r, b_c, c_r, c_c));
        v.push_back(twiceDist(b_r, b_c, d_r, d_c));
        v.push_back(twiceDist(c_r, c_c, d_r, d_c));
        sort(ALL(v));
        ans += (v[0] == v[1] && v[1] == v[2] && v[2] == v[3] && v[4] == v[5]);
    }
    cout << ans << endl;
    return 0;
}
