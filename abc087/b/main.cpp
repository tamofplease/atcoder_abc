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
    int a,b,c; cin >> a >> b >> c;
    int x; cin >> x;
    int ans = 0;
    rep(i, a+1) rep(j, b+1) rep(k, c+1) {
        if((i*500+j*100+50*k) == x) ans++;
    }
    cout << ans << endl;
    return 0;
}
