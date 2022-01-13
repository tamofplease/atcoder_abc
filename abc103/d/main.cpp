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
    int n, m; cin >> n >> m;
    vector<pair<int, int>> v(m);
    rep(i, m) cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());
    int ans = 1;
    int tail = v[0].first-1;
    Rep(i, m-1) {
        if(v[i].second > tail) {
            tail = v[i].first -1 ;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
