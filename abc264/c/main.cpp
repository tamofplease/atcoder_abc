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
    int h1, w1, h2, w2;
    cin >> h1 >> w1;
    vector<vector<int>> a(h1, vector<int>(w1));
    rep(i, h1) rep(j, w1) { cin >> a[i][j]; }
    cin >> h2 >> w2;
    vector<vector<int>> b(h2, vector<int>(w2));
    rep(i, h2) rep(j, w2) cin >> b[i][j];

    rep(i, (1 << h1)) {
        vector<int> rH;
        rep(bit1, h1 + 1) if (i & (1 << bit1)) rH.push_back(bit1);
        if ((int)rH.size() != h2) continue;
        rep(j, (1 << w1)) {
            vector<int> rW;
            rep(bit2, w1 + 1) if (j & (1 << bit2)) rW.push_back(bit2);
            if ((int)rW.size() != w2) continue;
            bool valid = true;
            rep(h, h2) rep(w, w2) {
                if (b[h][w] != a[rH[h]][rW[w]]) {
                    valid = false;
                }
            }
            if (valid) {
                std::puts("Yes");
                return 0;
            }
        }
    }
    std::puts("No");

    return 0;
}