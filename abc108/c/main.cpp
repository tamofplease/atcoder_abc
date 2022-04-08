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
    int n, k; cin >> n >> k;
    ll ans = ll(n / k) * ll(n / k) * ll(n / k);
    if(k%2 == 0) {
        ll cnt = 0;
        Rep(i, n) {
            if(i%k == k/2) cnt++;
        }
        ans += cnt * cnt * cnt;
    }
    cout << ans << endl;
    return 0;
}
