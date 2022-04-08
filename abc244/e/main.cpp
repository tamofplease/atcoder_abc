#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 998244353;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    int k,s,t,x; cin >> k >> s >> t >> x;
    s--;t--;x--;
    vector<vector<int>> from(n);
    rep(i,m) {
        int u,v; cin >> u >> v;
        u--;v--;
        from[u].push_back(v);
        from[v].push_back(u);
    }
    
    // dp[i][j].first <=> in i movement to go j and odd time to access x;
    // dp[i][j].second <=> in i movement to go j and even time to access x;
    vector<vector<pair<ll, ll>>> dp(k+1, vector<pair<ll,ll>>(n, {0,0}));
    dp[0][s] = {0, 1};
    for(int i=0;i<k;i++) {
        for(int j=0;j<n;j++) {
            for(int prev : from[j]) {
                if(j == x) {
                    dp[i+1][j].first += dp[i][prev].second;
                    dp[i+1][j].second += dp[i][prev].first;
                } else {
                    dp[i+1][j].first += dp[i][prev].first;
                    dp[i+1][j].second += dp[i][prev].second;
                }
                dp[i+1][j].first %= MOD;
                dp[i+1][j].second %= MOD;
            }
        }
    }
    cout <<  dp[k][t].second % MOD << endl;
    return 0;
}