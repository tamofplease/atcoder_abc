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

ll C(ll a, ll b) {
    if (b == 1) return a;
    if (b == 2) return a * (a - 1) / 2;
    return 1;
}

int main() {
    string s;
    cin >> s;
    const int n = s.length();
    int k;
    cin >> k;

    if (n < k) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll base = 1;
    rep(i, k) base *= 9;
    for (int i = k; i < n; i++) ans += base * C(i - 1, k - 1);
    int tmp_k = k;

    for (int i = 0; i < n; i++) {
        int a = s[i] - '0';
        if (a == 0) continue;
        int smaller = a - 1;
        if (i != 0) ans += C(n - i - 1, tmp_k) * base;
        base /= 9;
        ans += smaller * C(n - i - 1, tmp_k - 1) * base;
        if (--tmp_k == 0) break;
    }
    int cnt = accumulate(s.begin(), s.end(), 0, [](int prev, char cur) -> int { return prev + (cur != '0'); });
    if (cnt >= k) ans++;
    cout << ans << endl;

    return 0;
}
