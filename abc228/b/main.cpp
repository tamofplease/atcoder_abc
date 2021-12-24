#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n, x; cin >> n >> x;
    x--;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    ll ans = 0;
    vector<bool> know(n, false);
    while(!know[x]) {
        know[x] = true;
        ans++;
        x = a[x];
    }
    cout << ans << endl;
    return 0;
}
