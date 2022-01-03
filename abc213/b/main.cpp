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
    vector<ll> a(n+1);
    rep(i, n) cin >> a[i];
    ll ma = 0;
    ll sm = 0;
    ll ans = 0;
    rep(i, n) ma = max(a[i], ma);
    rep(i, n) {
        if(a[i] != ma) {
            if(sm < a[i]) {
                ans = i+1;
                sm = a[i];
            }
        } 
    }
    cout << ans << endl;
    return 0;
}
