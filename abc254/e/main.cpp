// "Copyright 2022 tam"
#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()

#define ll int64_t

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> to(n, vector<int>());
    rep(i, m) {
        int a, b;
        cin >> a >> b, a--, b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    int q;
    cin >> q;
    rep(i, q) {
        int x, k;
        cin >> x >> k, x--;
        set<int> been;
        been.insert(x);
        if (k != 0) {
            queue<pair<int, int>> q;
            q.emplace(x, 0);
            while (!q.empty()) {
                auto [cur, dep] = q.front();
                q.pop();
                been.insert(cur);
                if (dep == k) {
                    continue;
                }
                for (int nxt : to[cur]) {
                    if (been.find(nxt) != been.end()) {
                        continue;
                    }
                    q.emplace(nxt, dep + 1);
                }
            }
        }
        ll ans = 0;
        for (auto it = been.begin(); it != been.end(); it++) {
            ans += (*it) + 1;
        }
        cout << ans << endl;
    }
    return 0;
}
