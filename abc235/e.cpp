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
    int n, m, q; cin >> n >> m >> q;
    vector<pair<int,pair<int, pair<int, int>>>> edge;
    dsu d(n);
    rep(i, m) {
        int from, to, cost; cin >> from >> to >> cost;
        from--; to--;
        edge.push_back(make_pair(cost, make_pair(-1, make_pair(from, to))));
    }
    rep(i, q) {
        int u, v, w; cin >> u >> v >> w;
        v--; u--;
        edge.push_back(make_pair(w, make_pair(i, make_pair(u, v))));
    }
    vector<string> ans(q);

    sort(edge.begin(), edge.end());
    rep(i, edge.size()) {
        pair<int, pair<int, int>> val = edge[i].second;
        if(val.first != -1) {
            if(!d.same(val.second.first, val.second.second)) {
                ans[val.first] = "Yes";
            } else {
                ans[val.first] = "No";
            }
        } else {
            if(!d.same(val.second.first, val.second.second)) {
                d.merge(val.second.first, val.second.second);
            }
        }
    }
    rep(i, q) {
        cout << ans[i] << endl;
    }
    return 0;
}
