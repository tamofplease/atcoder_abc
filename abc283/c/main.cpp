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
    string s;
    cin >> s;
    const int n = s.length();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i != n && s[i] == '0' && s[i + 1] == '0') {
            i++;
        }
        ans++;
    }
    cout << ans << endl;

    return 0;
}