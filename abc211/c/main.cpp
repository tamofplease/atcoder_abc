#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    string s; cin >> s;
    int l = s.length();
    vector<ll> dp(l + 1);
    string res = "chokudai";
    rep(i, l) {
        if(s[i] == 'c') dp[i] = 1;
    }
    rep(j, 8) {
        int cnt = 0;
        rep(i, l) {
            if(s[i] == res[j]) {
                cnt += dp[i];
                cnt %= MOD;
            }
            if(s[i] == res[j+1]) dp[i] = cnt;
        }
    }
    ll ans = 0;
    rep(i, l) {
        if(s[i] == 'i') {
            ans += dp[i];
            ans %= MOD;
        }
    }
    cout << ans % MOD << endl;

    return 0;
}
