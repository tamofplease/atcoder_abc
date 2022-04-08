#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int a,b; cin >> a >> b;
    ll ans = 1;
    for(int i = b; i < a ; i++) {
        ans *= 32;
    }
    cout << ans << endl;
    return 0;
}
