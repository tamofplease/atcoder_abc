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
    int n, m; cin >> n >> m;
    dsu d(n);
    vector<int> a(m), b(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    int ans = 0;
    rep(i, m) {
        dsu d(n);
        rep(j, m) {
            if(i==j) continue;
            d.merge(a[j], b[j]);
        }
        if(!d.same(a[i], b[i])) ans++;
    }
    cout << ans << endl;
    return 0;
}
