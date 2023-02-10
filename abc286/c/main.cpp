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
    ll a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    ll ans = INT64_MAX;
    rep(i, n) {
        int df = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) df++;
        }
        ans = min(ans, a * i + b * df);
        reverse(ALL(s));
        char c = s.back();
        s.pop_back();
        reverse(ALL(s));
        s.push_back(c);
    }
    cout << ans << endl;

    return 0;
}
