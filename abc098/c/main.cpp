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
    int n; cin >> n; string s; cin >> s;
    vector<int> a(n+1,0), b(n+1,0);
    int ans = INT32_MAX;
    rep(i, n-1) {
        if(s[i] == 'W') a[i]++;
        a[i+1] += a[i];
        if(s[i]=='W') a[i]--;
    }
    for(int i=n-1;i>=0;i--) {
        if (s[i] == 'E') b[i]++;
        if(i-1>=0) b[i-1] += b[i];
        if (s[i] == 'E')b[i]--;
    }
    rep(i, n) {
        ans = min(ans, a[i]+b[i]);
    }
    cout << ans << endl;

    return 0;
}
