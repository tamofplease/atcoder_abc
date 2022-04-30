#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(j,n) for(int j=1;j<=n;j++)
#define mod 998244353
#define ll long long

int main() {
    int n,m,k; cin >> n >> m >> k;
    /// dp[i][j]; i番めまで見た時に全体のそうわがjになる通りの数
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    dp[0][0] = 1;
    Rep(i,n) {
        rep(j,k+1) {
            Rep(l,m) {
                if(j-l>=0) {
                    dp[i][j] += dp[i-1][j-l];
                    dp[i][j] %= mod;
                }
            }
        }
    }

    ll ans = 0;
    rep(i,k+1) {
        ans += dp[n][i];
        ans %= mod;
    }

    cout << ans << endl;

}