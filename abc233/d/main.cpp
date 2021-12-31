#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
const ll MOD = 1000000007;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    map<ll, ll> m;
    vector<ll> b(n);
    b[0] = a[0];
    Rep(i, n - 1) b[i] = b[i - 1] + a[i];
    ll ans = 0;
    m[0] = 1;
    rep(i, n) {
        ans += m[b[i] - k];
        m[b[i]]++;
    }
    cout << ans << endl;
    return 0;
}
