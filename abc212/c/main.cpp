#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
#define ALL(a) (a).begin(), (a).end()

int main(){
    int n, m; cin >> n >> m;    
    vector<int> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    sort(ALL(a));
    sort(ALL(b));
    int ater = 0;
    int bter = 0;
    int ans  = INT32_MAX;
    while(ater < n && bter < m) {
        ans = min(ans, abs(a[ater] - b[bter]));
        (a[ater] < b[bter] ? ater : bter)++;
    }
    cout << ans << endl;
    return 0;
}
