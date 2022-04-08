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
    int n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i, n) {
        cin >> a[i];
        a[i] -= (i+1);
        sum += a[i];
    }
    sort(a.begin(), a.end());
    
    ll ans = LLONG_MAX;
    for(ll i=(n/2)-1;i<=(n/2)+1;i++) {
        ll tmp = 0;
        rep(j, n) {
           tmp += abs(a[j]-a[i]);
        }
        ans = min(tmp, ans);
    }

    cout << ans << endl;
    return 0;
}
