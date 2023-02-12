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
    int n, m;
    cin >> n >> m;
    vector<string> s(n), t(m);
    rep(i, n) cin >> s[i];
    rep(i, m) cin >> t[i];
    int ans = 0;
    rep(i, n) {
        rep(j, m) {
            bool isValid = true;
            for (int k = 3; k < 6; k++) {
                if (s[i][k] != t[j][k - 3]) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans++;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}