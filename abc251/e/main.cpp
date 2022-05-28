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
    
    ll ans = 0;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto& ref : a) {
        cin >> ref;
    }

    vector<ll> nes(n), unnes(n);

    nes[0] = 0;
    unnes[0] = a[0];
    Rep(i, n-1) {
        unnes[i] = min(nes[i-1] + a[i], unnes[i-1] + a[i]);
        nes[i] = min(unnes[i-1], unnes[i]);
    }
    ans = min(nes[n-1] + a[n-1], unnes[n-1]);

    nes[0] = a[0];
    unnes[0] = a[0];
    Rep(i, n-1) {
        unnes[i] = min(nes[i-1] + a[i], unnes[i-1] + a[i]);
        nes[i] = min(unnes[i-1], unnes[i]);
    }

    cout << min(ans, min(unnes[n-1], nes[n-1])) << endl;

    return 0;
}