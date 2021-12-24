#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

struct edge {
    int from, to, cost;
};

bool compare(edge a, edge b) {
    return a.cost < b.cost;
}

int main(){
    int n,m; cin >> n >> m;
    vector<edge> edges(m);
    ll initialPoints = 0;
    rep(i, m) {
        int from, to, cost;
        cin >> from >> to >> cost;
        edges[i] = edge{from-1, to-1, cost};
        initialPoints += cost;
    }
    sort(edges.begin(), edges.end(), compare);
    dsu d(n);
    rep(i, m) {
        edge edg = edges[i];
        if(edg.cost < 0 || !d.same(edg.from, edg.to)) {
            d.merge(edg.from, edg.to);
            initialPoints -= edg.cost;
        }
    }
    cout << initialPoints << endl;
    return 0;
}
