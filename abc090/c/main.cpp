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
    ll n, m; cin >> n >> m;
    if(n==1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(n == 1 || m == 1) {
        cout << max((ll)0, max(n-2, m-2)) << endl;
        return 0;
    }
    cout << (n-2) * (m-2) << endl;
    return 0;
}