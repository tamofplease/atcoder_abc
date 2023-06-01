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
    vector<ll> memo(n + 1, 0);
    for (int a = 1; a <= n; a++) {
        for (int b = 1; b * a <= n; b++) {
            memo[a * b]++;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += memo[i] * memo[n - i];
    }
    cout << ans << endl;
    return 0;
}
