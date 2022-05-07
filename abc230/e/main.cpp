#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n; cin >> n;
    ll k;
    for(ll i=1;i<=n;i++) {
        if(i*i<=n) k = i;
        else break;
    }
    ll ans = 0;
    for(ll i=1;i<=k;i++) {
        ans += ((n/i) - (n/(i+1))) * i;
    }
    for(ll i=1;i<=n/(k+1);i++) ans += (n/i);
    cout << ans << endl;
    return 0;
}