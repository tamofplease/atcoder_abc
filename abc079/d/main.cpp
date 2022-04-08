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
    int h,w; cin>>h >>w;
    vector<vector<int>> to(10, vector<int>(10));

    rep(i, 10) rep(j, 10) {
        int c; cin >> c;
        to[i][j] = c;
    }
    rep(k, 10) rep(j, 10) rep(i, 10) {
        to[i][j] =  min(to[i][j], to[i][k] + to[k][j]);
    }

    ll ans= 0;

    rep(i, h) rep(j, w) {
        int a; cin >> a;
        if(a>0)  ans += to[a][1];
    }
    cout << ans << endl;

    return 0;
}
