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
    int n, x, y; cin >> n >> x >> y;
    vector<int> a(n), b(n);
    int a_sum = 0, b_sum = 0;
    rep(i, n) {
        cin >> a[i] >> b[i];
        a_sum += a[i]; b_sum += b[i];
    }

    vector<vector<int>> dp(301, vector<int>(301));
    int inf = 90001;
    rep(i, 301) rep(j, 301){
        dp[i][j] = inf;
    }
    dp[0][0] = 0;
    rep(k, n) {
        for(int i=300;i>=0;--i){
            for(int j=300;j>=0;--j) {
                if(i-a[k] >= 0 && j-b[k] >= 0 && dp[i-a[k]][j-b[k]] != inf) dp[i][j] = min(dp[i][j], dp[i-a[k]][j-b[k]] + 1);
                if(i-1>=0 && j-1>=0) dp[i - 1][j - 1] = min(dp[i][j], dp[i - 1][j - 1]);
                if(i-1>=0) dp[i - 1][j] = min(dp[i][j], dp[i - 1][j]);
                if(j-1>=0) dp[i][j - 1] = min(dp[i][j], dp[i][j - 1]);
            }
        }
    }

    if(dp[x][y] == inf) {
        cout << -1 << endl;
    } else {
        cout << dp[x][y] << endl;
    }

    return 0;
}
