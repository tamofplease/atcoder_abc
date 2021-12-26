#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define Rep(i,n) for(ll i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    ll n;cin >> n;
    vector<vector<ll>> a;
    vector<ll> t(n);
    rep(i, n) {
        ll k; cin >> t[i] >> k;
        vector<ll> b(k);
        rep(j, k) {
            cin >> b[j];
            b[j]--;
        }
        a.push_back(b);
    }
    set<ll> have;
    ll ans = 0;
    queue<ll> train;
    have.insert(n-1);
    for(ll nxt: a[n-1]) {
        if(have.find(nxt) == have.end()) {
            train.push(nxt);
            have.insert(nxt);
        }
    }
    ans += t[n-1];
    while(!train.empty()) {
        ll f = train.front(); train.pop();
        for(ll nxt: a[f]) {
            if(have.find(nxt) == have.end()) {
                train.push(nxt);
                have.insert(nxt);
            }
        }
        ans += t[f];
    }
    cout << ans << endl;
    return 0;
}
