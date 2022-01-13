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
    int n; cin >> n;
    vector<int> a(n+1);
    int ans = 0;
    rep(i, n) cin >> a[i];
    
    rep(i, n) ans += a[i] -1;
    cout << ans << endl;
    return 0;
}
