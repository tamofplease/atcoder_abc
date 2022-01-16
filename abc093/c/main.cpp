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
    int a,b,c; cin >> a >> b >> c;
    int ma = max(a, max(b,c));
    int ans = ma*3 - a - b - c;
    if(ans%2 == 0) {
        cout << ans / 2 << endl;
    } else {
        cout << (ans+3) / 2 << endl;
    }
    return 0;
}
