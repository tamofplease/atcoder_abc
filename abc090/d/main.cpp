// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

#define ll int64_t

int _main();

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    _main();
}

int _main() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int b = k + 1; b <= n; b++) {
        ll one_repeat = b - k;
        ll rep_num = n / b;
        ll rest = max(0, (n % b) - k + 1);
        ans += rest + one_repeat * rep_num;
        if (k == 0) ans--;
    }
    cout << ans << endl;
    return 0;
}
