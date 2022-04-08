#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;


int dp[11][200000];
int d, g;

void show() {
    rep(i, 30) {
        cout << i << " " << dp[d][i] << endl;
    }
}

int main(){
    cin >> d >> g;
    g/=100;
    vector<int> p(d), c(d);
    rep(i, d) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }
    rep(i, 11) rep(j, 110001) dp[i][j] = INT32_MAX;
    rep(i, 11) dp[i][0] = 0;
    Rep(i, d) {
        rep(k, 110000) {
            if(dp[i-1][k] < INT32_MAX) {
                rep(j, p[i-1]) {
                    int prob_num = j+1;
                    dp[i][k+prob_num*i] = min(min(dp[i-1][k+prob_num*i], dp[i][k+prob_num*i]), dp[i-1][k] + prob_num);
                }
                int prob_num = p[i-1];
                dp[i][k+prob_num*i+c[i-1]] = min(min(dp[i][k+prob_num*i+c[i-1]], dp[i][k+prob_num*i+c[i-1]]), dp[i-1][k] + prob_num);
            }
        }
        for(int k=109999;k>=0;k--) {
            dp[i][k] = min(dp[i][k], dp[i][k+1]);
        }
    }
    cout << dp[d][g] << endl;
    return 0;
}
