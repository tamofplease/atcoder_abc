// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++ )
#define Rep(i, n) for (int i = 1 ; i <= n ; i++ )

#define ll int64_t

int _main();

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    _main();
}

int _main() {
    cout << int('a') << " " << int('z') << endl;
    cout << int('A') << " "  << int('Z') << endl;
    int n, k;
    cin >> n >> k;
    int ans = 0;
    // a < b
    for (int i = k ; i <= n ; i++) {
        ans += min(n-i, n-k);
    }

    /// a > b
    for (int a = 1 ; a <= n ; a++) {
        for (int b = k + 1 ; b <= min(a-1, a-k) ; b++) {
            if (a % b >= k) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
