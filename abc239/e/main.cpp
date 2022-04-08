#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

struct Q {
    int k, i;
    Q(int k, int i):k(k),i(i){}
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n, q; cin >> n >> q;
    vector<int> x(n);
    vector<vector<int>> to(n);
    rep(i,n) cin >> x[i];
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<vector<Q>> qry(n);

    rep(i, q) {
        int v, k; cin >> v >> k;
        v--;k--;
        qry[v].emplace_back(k,i);
    }

    vector<int> ans(q);

    const int K = 20;
    auto merge = [&] (vector<int>& a, vector<int>& b) {
        a.insert(a.begin(), ALL(b));
        sort(a.rbegin(), a.rend());
        a.resize(K);
    };

    auto dfs = [&] (auto f, int c, int p=-1) -> vector<int> {
        vector<int> res(K);
        res[0] = x[c];
        for(int n : to[c]) {
            if(n == p) continue;
            auto d = f(f, n, c);
            merge(res, d);
        }
        for (auto [k,i] : qry[c]) {
            ans[i] = res[k];
        }
        return res;
    };
    dfs(dfs, 0);

    for(int i : ans) {
        cout << i << endl;
    }

    return 0;
}
