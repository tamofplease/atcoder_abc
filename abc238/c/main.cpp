#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 998244353;
using mint = modint998244353;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    int digit = to_string(n).length();
    if(digit == 1) {
        cout << ((1+n) * n) / 2 << endl; 
        return 0;
    }
    ll ans = 45;
    ll tmp = 9;
    ll border = 99;
    rep(i, digit-1) {
        ll target = min(border, n) - tmp;
        if(target < 0) target += MOD;
        target %= MOD;
        ans += ((target + 1) * target) / 2;
        ans %= MOD;
        tmp *= 10; tmp += 9; tmp %= MOD;
        border *= 10; border += 9;
    }
    if(ans < 0) ans += MOD;
    cout << ans % MOD << endl;

    // 1 ~ 9: => n => ((1+n) * n) / 2; 
    // 10 ~ 99 => n-9 => (n-8) * (n-9) / 2;
    // 100 ~ 999 => n-99 => (n-98) * (n-99) / 2;


    return 0;
}
