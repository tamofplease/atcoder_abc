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
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v, u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    queue<int> q;
    vector<bool> been(n, false);
    set<int> centers;

    rep(i, n) {
        if (graph[i].size() == 1) {
            q.push(i);
        }
    }
    vector<int> ans;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (been[cur]) continue;

        int center = -1;
        for (int nxt : graph[cur]) {
            if (!been[nxt]) center = nxt;
        }
        if (center == -1) continue;
        ans.push_back(graph[center].size());
        been[center] = true;
        for (int nxt : graph[center]) {
            if (been[nxt]) continue;
            been[nxt] = true;
            if (graph[nxt].size() == 1) {
                continue;
            }
            for (int nnxt : graph[nxt]) {
                if (been[nnxt]) continue;
                q.push(nnxt);
            }
        }
    }

    sort(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
