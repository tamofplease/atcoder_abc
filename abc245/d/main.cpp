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
    int n,m; cin>> n >> m;
    vector<int> a(n+1);
    vector<int> c(n+m+1);
    vector<int> b(m+1, 0);
    rep(i,n+1) cin >> a[i];
    rep(i,n+m+1) cin >> c[i];
    for(int i=m; i>=0; i--) {
        b[i] = c[i+n] / a[n];
        for(int j=0;j<=n;j++) c[i+j] -= b[i] * a[j];
    }
    cout << b[0];
    Rep(i, m) cout << " " << b[i];
    cout << endl;
    return 0;
}