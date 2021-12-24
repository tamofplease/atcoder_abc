#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define Rep(i,n) for(ll i=1;i<=n;i++)
const ll MOD = 1000000007;
ll N;
int main() {
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    
    ll ans = 0;
    ll s = 0, b = 0;
    ll max_b = 0;
    rep(i, N) {
        b += A[i];
        max_b = max(b, max_b);
        ans = max(ans, max_b + s);
        s += b;
    }
    cout << ans << endl;
    return 0;
}
