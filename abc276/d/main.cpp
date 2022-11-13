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
    int n;
    cin >> n;
    vector<int> a(n);
    int cur_gcd = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!cur_gcd)
            cur_gcd = a[i];
        else
            cur_gcd = gcd(cur_gcd, a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tgt = a[i] / cur_gcd;
        while (tgt % 2 == 0) {
            tgt /= 2;
            ans++;
        }
        while (tgt % 3 == 0) {
            tgt /= 3;
            ans++;
        }
        if (tgt != 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
