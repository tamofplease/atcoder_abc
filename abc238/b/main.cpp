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
    int n; cin >> n;
    vector<bool> table(360, false);
    int cur = 0;
    table[0] = true;
    rep(i, n) {
        int a; cin >> a;
        cur += a;
        cur %= 360;
        table[cur] = true;
    }
    int ans = 0;
    int tmp = 0;
    rep(i, 361) {
        if(table[i%360]) {
            ans = max(ans, tmp);
            tmp = 0;
        }
        tmp++;
    }
    cout << ans << endl;
    
    return 0;
}
