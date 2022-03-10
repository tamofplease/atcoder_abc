#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    ll ans = 0;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<ll> nxt(n);
    rep(i,n) {
        nxt[i] = (i + a[i]) % n;
    }
    vector<bool> hasCome(n, false);
    ll cur = 0;

    /// begin => loop
    while(k > 0 && !hasCome[cur]) {
        ans += a[cur];
        hasCome[cur] = true;
        k--; cur = nxt[cur];
    }
    if(k == 0) {
        cout<<ans<<endl;
        return 0;
    }

    /// loop => end of loop
    ll goal = cur;
    ll sum = a[cur];
    // ans += a[cur];
    cur = nxt[cur];
    ll length = 1;
    while(cur != goal) {
        sum += a[cur];
        cur = nxt[cur];
        length++;
    }
    ll loopTimes = (ll)(k / length);
    ans += loopTimes * sum;
    ll remain = k % length;


    /// end of loop
    rep(i, remain) {
        ans += a[cur];
        cur = nxt[cur];
    }
    cout << ans << endl;
    
    /// 2 1 6 3 1
    /// 5, 3
    /// 0 => 2 => 3 => 1 => 2 => 3 => 1 => 2 
    /// 2 => 8 => 11=> 12=>18 => 21=> 22=> 28
    return 0;
}
