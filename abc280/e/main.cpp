#include <bits/stdc++.h>

#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
int main() {
    int n, p;
    cin >> n >> p;
    mint P = mint(p) / mint(100), Q = mint(1) - P;
    vector<mint> fact(n + 1);
    fact[0] = mint(1);
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * mint(i);
    mint ans = 0;
    for (int k = 1; k <= n; k++) {
        if (k >= (n - k)) ans += mint(k) * fact[k] / (fact[n - k] * fact[2 * k - n]) * P.pow(n - k) * Q.pow(2 * k - n);
        if ((k - 1) >= (n - k))
            ans +=
                mint(k) * fact[k - 1] / (fact[n - k] * fact[2 * k - n - 1]) * P.pow(n - k + 1) * Q.pow(2 * k - n - 1);
    }
    cout << ans.val() << endl;
    return 0;
}