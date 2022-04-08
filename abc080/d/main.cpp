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
    int N, C; cin >> N >> C;
    vector<vector<int>> d(C+1, vector<int>(100001));
    rep(i, N) {
        int s,t,c; cin >> s >> t >> c;
        d[c][s]++;
        d[c][t]--;
    }
    vector<int> s, t;
    Rep(i, C) {
        rep(j, 100000) {
            d[i][j+1] += d[i][j];
        }
    }
    Rep(i, C) {
        rep(j, 100001) {
            if(d[i][j]==1) {
                s.push_back(j);
                while(d[i][j] == 1) {
                    j++;
                }
                t.push_back(j);
            }
        }
    }


    int ans = 0;
    vector<int> dp(200001, 0);
    rep(i, (int)s.size()) {
        dp[s[i]*2-1]++;
        dp[t[i]*2]--;
    }
    rep(i, 200000) {
        dp[i+1] += dp[i];
        ans = max(dp[i+1], ans);
    }
    cout << ans << endl;





    

    return 0;
}
