#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int s, t;
int main(){
    cin >> s >> t;
    int ans = 0;
    rep(i,101) rep(j, 101) rep(k, 101) {
        if(i + j + k <= s && i * j * k <= t) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
