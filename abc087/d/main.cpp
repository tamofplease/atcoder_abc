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
    int n, m; cin >> n >> m;
    vector<int> l(m), r(m), d(m);
    vector<bool> visited(n, false);
    rep(i, m) {
        cin >> l[i] >> r[i] >> d[i];
        l[i]--; r[i]--;
    }
    queue<int> q;
    q.push
    map<int, int> ma;
    rep(i, m) {
        ma[r[i]] = ma[l[i]] + d[i];

    }
    for(int i=m-1;i>=0;i--) {
        ma[l[i]] = ma[r[i]] - d[i];
    }
    rep(i, m) {
        if(ma[r[i]] != ma[l[i]] + d[i]) {
            puts("No");
            return 0;
        }
    }
    for(int i=m-1;i>=0;i--) {
        if(ma[l[i]] != ma[r[i]] - d[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
