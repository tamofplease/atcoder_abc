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
    ll x; cin >> x;
    ll res = x / 10;
    ll rem = x % 10;
    if(x >= 0) cout << res << endl;
    else {
        if(rem == 0) cout << res << endl;
        else cout << res - 1 << endl;
    }
    return 0;
}
