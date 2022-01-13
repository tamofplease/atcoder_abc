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
    ll d, n; cin >> d >> n;
    if(n==100) n+=1;
    if(d==0) {
        cout << n << endl;
        return 0;
    }
    if(d==1) {
        int ans = 100 * n;
        cout << ans << endl;
        return 0;
    }
    int ans = 10000 * n;
    cout << ans << endl;
    return 0;
}
