#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
using mint = modint998244353;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<mint> dp(10,1);
    rep(i,n-1) {
        vector<mint> tmp = dp;
        Rep(j,9) {
            if(j!=1) dp[j] += tmp[j-1];
            if(j!=9) dp[j] += tmp[j+1];
        }
    }
    mint ans = 0;
    Rep(i,9) ans += dp[i];
    cout << ans.val() << endl;
    return 0;
}