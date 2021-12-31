#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

struct dt {
    ll currentCount;
    ll sum;
};

int main(){
    ll n, x; cin >> n >> x;
    vector<vector<ll>> a;
    vector<ll> l(n);
    rep(i, n) {
        cin >> l[i];
        vector<ll> b(l[i]);
        rep(j, l[i]) cin >> b[j];
        a.push_back(b);
    }

    queue<dt> q;
    rep(i, l[0]) {
        q.push({0, a[0][i]});
    }
    ll ans = 0;
    while(!q.empty()) {
        dt d = q.front(); q.pop();
        if(d.currentCount == n-1) {
            if(d.sum == x) {
                ans++;
            }
            continue;
        }
        ll currentCount = d.currentCount + 1;
        ll length = l[currentCount];
        vector<ll> b = a[currentCount];
        rep(i, length) {
            if(d.sum > x / b[i]) continue;
            q.push({currentCount, (ll)d.sum * b[i]});
        }
    }
    cout << ans << endl;
    return 0;
}
