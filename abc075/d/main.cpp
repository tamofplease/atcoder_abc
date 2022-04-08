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
    int n, k; cin >> n >> k;
    vector<pair<ll, ll>> p(n);
    rep(i, n) cin >> p[i].first >> p[i].second;
    sort(ALL(p));
    ll ans = INT64_MAX;
    rep(i, n-k+1) {
        ll mi = INT64_MAX, ma = INT64_MIN;
        for(int j=i;j<i+k;j++) {
            mi = min(p[j].second, mi);
            ma = max(p[j].second, ma);
        }
        ll tmp = abs(ma - mi) * abs(p[i+k-1].first - p[i].first);
        ans = min(tmp, ans);
    }
    rep(i, n) swap(p[i].second, p[i].first);
    sort(ALL(p));
    rep(i, n - k + 1) {
        ll mi = INT64_MAX, ma = INT64_MIN;
        for (int j = i; j < i + k; j++) {
            mi = min(p[j].second, mi);
            ma = max(p[j].second, ma);
        }
        ll tmp = abs(ma - mi) * abs(p[i + k - 1].first - p[i].first);
        ans = min(tmp, ans);
    }
    cout << ans << endl;

    
    return 0;
}
