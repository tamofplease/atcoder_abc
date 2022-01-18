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
    int h, w, d; cin >> h >> w >> d;
    unordered_map<int, pair<int, int>> ma;
    int mv = w * h;
    vector<ll> costs(mv+1, 0);
    rep(i, h) rep(j, w) {
        int a; cin >> a;
        ma[a] = make_pair(i, j);
    }
    int q; cin >> q;
    vector<int> l(q), r(q);
    rep(i, q) cin >> l[i] >> r[i];
    Rep(k, mv) {
        int nxk = k + d;
        if(nxk <= mv) {
            int curI = ma[k].first, curJ = ma[k].second;
            int nextI = ma[nxk].first, nextJ = ma[nxk].second;    
            costs[nxk] = costs[k] + abs(curI - nextI) + abs(curJ - nextJ);
        }
    }
    rep(i, q) {
        cout << costs[r[i]] - costs[l[i]] << endl;
    }



    return 0;
}
