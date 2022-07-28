// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    map<P, int> color;
    vector<vector<int>> to(n);
    vector<P> index;
    rep(i, n - 1) {
        int a, b;
        cin >> a >> b, a--, b--;
        to[a].push_back(b);
        index.emplace_back(a, b);
    }
    queue<P> q;
    q.emplace(-1, 0);
    while (!q.empty()) {
        auto [c, cur] = q.front();
        q.pop();
        int cc = 1;
        for (int nxt : to[cur]) {
            if (cc == c) cc++;
            color[{cur, nxt}] = cc;
            q.emplace(cc, nxt);
            cc++;
        }
    }
    int colors = 0;
    rep(i, n) { colors = max(colors, color[index[i]]); }
    cout << colors << endl;
    rep(i, n - 1) cout << color[index[i]] << endl;
    return 0;
}
