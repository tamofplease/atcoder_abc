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
    string s;
    cin >> n >> s;
    int ans = -1, cur = -1;
    for (char c : s) {
        if (c == '-') {
            if (cur > 0) ans = max(cur, ans);
            cur = 0;
        }
        if (cur < 0) continue;
        if (c == 'o') cur++;
    }
    if (cur > 0) ans = max(cur, ans);
    reverse(s.begin(), s.end());
    cur = -1;
    for (char c : s) {
        if (c == '-') {
            if (cur > 0) ans = max(cur, ans);
            cur = 0;
        }
        if (cur < 0) continue;
        if (c == 'o') cur++;
    }
    if (cur > 0) ans = max(cur, ans);
    cout << ans << endl;
}