// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n;
    cin >> n;
    ll ans = 0;
    Rep(i, n) {
        int cur = i;
        for (int j = 2; j * j <= n; j++) {
            while (cur % (j * j) == 0) {
                cur /= (j * j);
            }
        }
        for (int j = 1; j * j * cur <= n; j++) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
