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
    int n, x; cin >> n >> x;
    vector<int> dp(10201, -1);
    dp[0] = 0;
    rep(i,n) {
        int a,b; cin >> a >> b;
        for(int j=10000;j>=0;j--) {
            if(dp[j] == i) {
                dp[j+a] = i+1;
                dp[j+b] = i+1;
            }
        }
    }
    if(dp[x] == n) puts("Yes");
    else puts("No");
    return 0;
}
