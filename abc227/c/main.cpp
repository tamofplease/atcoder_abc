#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    ll n;cin >> n;
    ll ans = 0;
    for(ll a = 1; a * a * a <= n ; a ++) {
        for(ll b = a; a * b * b <=n ; b++) {
            ll ma =  n / (a * b);
            ans += ma - b  + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
