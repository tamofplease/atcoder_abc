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
    int n, a, b, c;

    cin >> n >> a >> b >> c;
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    int ans = INT32_MAX;
    for (int i = 0; i < (1 << (2 * n)); i++) {
        vector<int> cur;
        for (int bit = 0; bit < (2 * n); bit += 2) {
            int tgt = 0;
            if (i & (1 << bit)) tgt += 1;
            if (i & (1 << (bit + 1))) tgt += 2;
            cur.push_back(tgt);
        }
        vector<int> boo(3, 0);
        int score = 0;
        rep(j, n) {
            if (cur[j] == 3) continue;
            if (boo[cur[j]] != 0) score += 10;
            boo[cur[j]] += l[j];
        }
        score += abs(boo[0] - a) + abs(boo[1] - b) + abs(boo[2] - c);
        if (boo[0] == 0 || boo[1] == 0 || boo[2] == 0) continue;
        ans = min(ans, score);
    }

    cout << ans << endl;
    return 0;
}
