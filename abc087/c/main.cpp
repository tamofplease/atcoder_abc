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
    vector<int> a(n),b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n-1) {
        a[i+1] += a[i];
        b[n-i-2] += b[n-i-1];
    }
    int ans = 0;
    rep(i, n) {
        ans = max(ans, a[i] + b[i]);
    }
    cout << ans << endl;
    return 0;
}
