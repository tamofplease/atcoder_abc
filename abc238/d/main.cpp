#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

bool solve() {
    ll x, y; cin >> x >> y;
    bool carry = false;
    while(x > 0 || y > 0) {
        if(x&1) {
            if((y&1) ^ carry) return false;
            carry = true;
        } else if(y&1) carry = false;
        x >>= 1,y >>= 1;
    }
    return !carry;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    rep(i, t) solve() ? puts("Yes") : puts("No");
    return 0;
}
