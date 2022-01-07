#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 998244353;
using mint = modint998244353;

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int bm = b[n-1]+1;
    vector<mint> dp(bm);
    for(int i=a[0];i<=b[0];i++) dp[i]=1;
    Rep(i, n-1) {
        rep(j, bm) {
            if(j<a[i-1] || b[i-1]<j) dp[j] = 0;
            if(j>0) dp[j] += dp[j-1];
        }
    }
    mint ans = 0;
    for(int i=a[n-1];i<bm;i++) {
        ans += dp[i].val();
    }
    cout << ans.val() << endl;
    return 0;
}
