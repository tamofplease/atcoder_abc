// "Copyright 2022 tam"
#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0 ; i < n ; i++)
#define Rep(i, n) for (int i = 1 ; i <= n ; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

using P = pair<int, int>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        to[u].push_back(v);
    }
    int s, t;
    cin >> s >> t, s--, t--;
    vector<vector<int>> colors(n, vector<int>(3, -1));
    queue<P> q;
    q.emplace(0, s);
    while (!q.empty()) {
        auto [color, cur] = q.front();
        q.pop();
        if (colors[cur][color % 3] != -1) {
            continue;
        }
        colors[cur][color % 3] = color / 3;
        for (int nxt : to[cur]) {
            q.emplace(color + 1, nxt);
        }
    }

    cout << colors[t][0] << endl;
    return 0;
}