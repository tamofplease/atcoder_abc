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
    string s, t;
    cin >> s >> t;
    const int sn = s.length(), tn = t.length();
    for (int i = 0; i <= sn - tn; i++) {
        bool ok = true;
        for (int j = 0; j < tn; j++) {
            if (s[i + j] != t[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
