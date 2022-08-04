// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

using mint = modint1000000007;

int modPow(mint a, mint n) {
    if (n == 0) return 1;
    if (n == 1) return a.val();
    if (n.val() % 2 == 1) return (a * modPow(a, n - 1)).val();
    mint t = modPow(a, n / 2);
    return (t * t).val();
}

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    mint ans = modPow(2, n);
    ans--;
    mint aa = 1;
    mint bb = 1;
    Rep(i, a) {
        aa *= n - i + 1;
        aa /= i;
    }
    ans -= aa;
    Rep(i, b) {
        bb *= n - i + 1;
        bb /= i;
    }
    ans -= bb;

    cout << ans.val() << endl;
    return 0;
}
