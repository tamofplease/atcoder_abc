#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main(){
    ll n; cin >> n;
    vector<ll> s(n), t(n);
    rep(i, n*2) cin >> ((i>=n) ? t[i-n] : s[i]);
    vector<ll> ans = t;
    rep(i, n*2) {
        int frontSeat = (i - 1 + n) % n;
        int currentSeat = i % n;
        ans[currentSeat] = min(ans[currentSeat], s[frontSeat] + ans[frontSeat]);
    }
    rep(i, n) {
        cout << ans[i] << endl;
    }
    return 0;
}
