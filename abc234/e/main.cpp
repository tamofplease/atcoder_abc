#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

set<ll> gen_df(int digit, int df) {
    set<ll> res;
    Rep(i, 9) {
        ll tmp = i, k = i;
        bool valid = true;
        rep(j, digit-1) {
            if(k-df < 0) valid = false;
            tmp *= 10;
            tmp += k - df;
            k -= df;
        }
        if(valid) res.insert(tmp);
        tmp = i, k = i;
        valid = true;
        rep(j, digit-1) {
            if(k+df > 9) valid = false;
            tmp *= 10;
            tmp += k + df;
            k += df;
        }
        if (valid) res.insert(tmp);
    }
    return res;
}

int main(){
    ll n; cin >> n;
    set<ll> res;res.insert(0);
    res.insert(111111111111111111);
    rep(i, 18) rep(j, 10) {
        set<ll> tm = gen_df(i, j);
        res.merge(tm);
    }
    ll ans = *res.lower_bound(n);
    cout << ans << endl;
    return 0;
}
