#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;


// dp[i] 水i*100gにとける砂糖の最大量
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >>f;
    f/=100;
    vector<int> dp(f+1, -1);
    dp[0] = 0;
    Rep(i, f) {
        if(dp[i-a] == 0) dp[i] = 0;
        if(dp[i-b] == 0) dp[i] = 0;
    }
    Rep(i, f) cout << dp[i] << endl;
    Rep(i, f) {
        if(dp[i-c] >= 0) {
            while(true) {
                if(dp[i] == -1 && c <= i*e) {
                    dp[i] = c;
                }
                else if(dp[i]+c <= i*e) {
                    dp[i] += c;
                } else {
                    break;
                }
            }
        }
        if(dp[i-d] >= 0) {
            while(true) {
                if( dp[i] == -1 && d <= i*e) {
                    dp[i] = d;
                } else if(dp[i] + d <= i*e) {
                    dp[i] += d;
                } else {
                    break;
                }
            }
        }
    }
    Rep(i, f) cout << dp[i] << endl;
    int ma = 0;
    int sug = 0, wat = 0;
    Rep(i, f) {
        if(i*100+dp[i] <= f && ma < 100*dp[i]/(100*i+dp[i])) {
            ma = 100 * dp[i] / (100 * i + dp[i]);
            sug = dp[i], wat = i * 100 + dp[i];
        }
    }
    cout << wat << " " << sug << endl;
    return 0;
}
