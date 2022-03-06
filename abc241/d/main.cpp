#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int q; cin >> q;
    multiset<ll> se;
    rep(i,q) {
        int type; cin >> type;
        ll x; cin >> x;
        if(type == 1) {
            se.insert(x);
            continue;
        }
        int k; cin >> k;
        ll ans = -1;
        if(type == 2) {
            auto iter = se.upper_bound(x);
            bool isOk = true;
            rep(j,k) {
                if(iter == se.begin()) {
                    isOk = false;
                    break;
                }
                iter--;
            }
            if(isOk) ans = *iter;
        }
        if(type == 3) {
            auto iter = se.lower_bound(x);
            bool isOk = true;
            rep(j,k-1) {
                if(iter == se.end()) {
                    isOk = false;
                    break;
                }
                iter++;
            }
            if(isOk && iter != se.end()) {
                ans = *iter;
            }
        }
        cout << ans << endl;

    }
    return 0;
}
