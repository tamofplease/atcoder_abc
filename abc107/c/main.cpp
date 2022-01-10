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
    int n, k; cin >> n >> k;
    vector<ll> x(n);
    ll ans = 1000000000;
    rep(i, n) cin >> x[i];

    rep(i, n-k+1) {
        int left = i, right = i+k-1;
        if(x[right] <= 0) ans = min(ans, -1 * x[left]);
        else if(x[left] > 0) ans = min(ans, x[right]);
        else {
            ll dbl = min(-1 * x[left],x[right]);
            ans = min(ans, x[right] - x[left] + dbl);
        }
    }
    cout << ans << endl;
    return 0;
}
