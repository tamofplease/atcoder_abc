#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

#define ll long long

int main() {
    ll n, C; cin >> n >> C;
    vector<int> a(n), b(n), c(n);
    rep(i,n) cin >> a[i] >> b[i] >> c[i];
    map<ll, ll> ma;
    rep(i,n) {
        ma[a[i]-1] += c[i];
        ma[b[i]] -= c[i];
    }
    pair<ll, ll> prev = {-1, -1};
    ll ans = 0;
    for(auto it = ma.begin() ; it != ma.end() ; it++) {
        if(prev.first != -1) {
            ma[it->first] += prev.second;
            ans += min(prev.second, C) * (it->first - prev.first);
        }
        prev = {it->first, it->second};
    }

    cout << ans << endl;
    
    return 0;
}