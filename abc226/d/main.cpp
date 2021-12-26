#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main(){
    int n; cin >> n;
    vector<ll> x(n),y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    set<pair<ll, ll>> se;
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            ll X = x[i] - x[j];
            ll Y = y[i] - y[j];
            ll a = gcd(X, Y);

            se.insert(make_pair(X / a, Y / a));
        }
    }
    cout << se.size() << endl;
    
    return 0;
}
