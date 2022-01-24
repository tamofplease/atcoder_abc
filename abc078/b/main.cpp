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
    int x, y, z; cin >> x >> y >> z;
    x -= z;
    int ans = 0;
    while(x-z-y>=0) {
        x -= z;
        x -= y;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
