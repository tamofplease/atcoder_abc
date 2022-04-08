#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> x(q), k(q);
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, q) {
        cin >> x[i] >> k[i];
        k[i]--;
    }
    map<int, vector<int>> ma;
    rep(i, n) {
        if(ma.find(a[i]) != ma.end()) {
            ma[a[i]].push_back(i);
        } else {
            ma[a[i]].push_back(i);
        }
    }
    rep(i, q) {
        if(ma[x[i]].size() > k[i]) {
            cout << ma[x[i]][k[i]]+1 << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
