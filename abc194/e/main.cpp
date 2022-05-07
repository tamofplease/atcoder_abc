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
    int n,m; cin >> n >> m;
    vector<int> a(n);
    for(auto &ref : a) cin >> ref;
    vector<int> hold(1500001, 0);
    rep(i,m) hold[a[i]]++;
    int ans = 1500000;
    rep(i, 1500001) {
        if(hold[i] == 0) {
            ans = i;
            break;
        }
    }
    rep(i,n-m) {
        int leave = a[i], insert = a[i+m];
        hold[leave]--;
        hold[insert]++;
        if(hold[leave] == 0) {
            ans = min(ans, i);
        }
    }

    cout << ans << endl;
    return 0;
}