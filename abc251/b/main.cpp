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
    int n, w;
    cin >> n >> w;
    vector<int> a(n);
    for (auto& ref : a) {
        cin >> ref;
    }
    vector<bool> valid(w+1);
    rep(i, n) {
        rep(j, i) {
            rep(k, j) {
                if (a[i] + a[j] + a[k] <= w) {
                    valid[a[i] + a[j] + a[k]] = true;
                }
            }
            if (a[i] + a[j] <= w)
                valid[a[i] + a[j]] = true;
        }
        valid[a[i]] = true;
    }
    int ans = 0;
    rep(i, w+1) {
        ans += valid[i];
    }
    cout << ans << endl;
    return 0;
}