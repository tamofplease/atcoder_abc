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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<bool>> been(h, vector<bool>(w, false));
    int cw = 0, ch = 0;
    map<char, pair<int, int>> ma = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
    while (!been[ch][cw]) {
        been[ch][cw] = true;
        char c = s[ch][cw];
        pair<int, int> p = ma[c];
        ch += p.first, cw += p.second;
        if (0 <= ch && ch < h && 0 <= cw && cw < w) {
            continue;
        }
        ch -= p.first, cw -= p.second;
        cout << ch + 1 << " " << cw + 1 << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}
