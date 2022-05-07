#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)

#define ll long long

int main() {
    ll n; cin >> n;
    ll k;

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    } 
    if(n == 2) {
        cout << 3 << endl;
        return 0;
    }

    vector<ll> divisor;
    for(ll i=1;i<=n;i++) {
        divisor.push_back(i);
        divisor.push_back(n/i);
    }
    cout << divisor.size() << endl;
    sort(divisor.begin(), divisor.end());
    ll ans = 0;
    ll prev = -1;
    for(ll cur : divisor) {
        if(prev == -1) {
            ans += n;
        } else {
            ans += (cur-prev) * (n / cur);
        }
        prev = cur;
    }
    cout << ans << endl;
    return 0;
}