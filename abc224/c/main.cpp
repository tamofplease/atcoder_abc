#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n; cin >> n;
    vector<ll> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    ll ans = 0;
    rep(i, n) {
        rep(j, i) {
            ll dfx = x[i] - x[j];
            ll dfy = y[i] - y[j];
            ll gc = gcd(dfx, dfy);
            dfy /= gc; dfx /= gc;
            rep(k, j) {
                ll dfx2 = x[i] - x[k];
                ll dfy2 = y[i] - y[k];
                ll gc2 = gcd(dfx2, dfy2);
                dfy2 /= gc2; dfx2 /= gc2;
                if((dfx == dfx2 && dfy == dfy2) || (dfx == -1 * dfx2 && dfy == -1 * dfy2)) {
                } else {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
