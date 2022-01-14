#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;
int n;

int main(){
    cin >> n;
    vector<int> dp(110000);
    rep(i, 100001) {
        dp[i] = i;
    }
    
    ll six = 1;
    ll nine = 1;
    while(six <= 100000) {
        six *= 6;
        rep(j, n+1) {
            if(j-six>=0) dp[j] = min(dp[j-six]+1, dp[j]);
        }
    }
    while(nine <= 100000) {    
        nine *= 9;
        rep(j, n+1) {
            if(j-nine>=0) dp[j] = min(dp[j-nine]+1, dp[j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}
