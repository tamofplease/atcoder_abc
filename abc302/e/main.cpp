// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n, q;
    cin >> n >> q;
    int cnt = n;
    vector<set<int>> g(n);
    rep(i, q) {
        int x;
        cin >> x;
        if (x == 1) {
            int u, v;
            cin >> u >> v, u--, v--;
            if (g[u].size() == 0) cnt--;
            if (g[v].size() == 0) cnt--;
            g[u].insert(v);
            g[v].insert(u);
        }
        if (x == 2) {
            int v;
            cin >> v, v--;
            if (g[v].size() != 0) cnt++;
            for (int con : g[v]) {
                g[con].erase(v);
                if (g[con].size() == 0) cnt++;
            }
            g[v] = {};
        }
        cout << cnt << endl;
    }
    return 0;
}
