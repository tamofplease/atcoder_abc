#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<ll>> cost(n, vector<ll>(n, INT32_MAX));
    rep(i,n) cost[i][i] = 0;
    rep(i,m) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        cost[a][b] = c;
    }
    ll ans = 0;
    rep(k,n) {
        vector<vector<ll>> tmp(n, vector<ll>(n, 0));
        rep(from, n) rep(to, n) {
            tmp[from][to] = min(cost[from][to], (ll)cost[from][k] + cost[k][to]);
            if(tmp[from][to] < INT32_MAX) ans += tmp[from][to];
        }
        cost = tmp;
    }

    cout << ans << endl;
    return 0;
}