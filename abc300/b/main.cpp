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
    vector<string> a(h), b(h);
    rep(i, h) { cin >> a[i]; }
    rep(i, h) { cin >> b[i]; }
    rep(i, h) rep(j, w) {
        bool diff = false;
        rep(k, h) rep(l, w) {
            if (a[k][l] != b[(k + i) % h][(l + j) % w]) diff = true;
        }
        if (!diff) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");

    return 0;
}
