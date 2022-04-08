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
    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(ALL(a));sort(ALL(c));
    ll ans = 0;
    rep(i, n) {
        auto a_iter = lower_bound(ALL(a), b[i]);
        auto c_iter = upper_bound(ALL(c), b[i]);
        if(a_iter == a.begin() || c_iter == c.end()) continue;
        ans += ((a_iter - a.begin())) * (n - (c_iter - c.begin()));
    }
    cout << ans << endl;
    return 0;
}
