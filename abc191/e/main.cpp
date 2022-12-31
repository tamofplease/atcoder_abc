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
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> to(n);
    vector<int> slf(n, INT32_MAX);
    rep(i, m) {
        int a, b, c;
        cin >> a >> b >> c, a--, b--;
        if (a == b) {
            slf[a] = min(slf[a], c);
            continue;
        }
        to[a].push_back({c, b});
    }
    vector<vector<int>> ans(n, vector<int>(n, INT32_MAX));

    rep(i, n) {
        ans[i][i] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, i});
        while (!pq.empty()) {
            vector<int> cur = pq.top();
            pq.pop();
            if (ans[i][cur[1]] < cur[0]) continue;
            for (vector<int> nxt : to[cur[1]]) {
                if (ans[i][nxt[1]] > ans[i][cur[1]] + nxt[0]) {
                    ans[i][nxt[1]] = ans[i][cur[1]] + nxt[0];
                    pq.push({ans[i][nxt[1]], nxt[1]});
                }
            }
        }
    }
    vector<int> res(n, INT32_MAX);
    for (int start = 0; start < n; start++) {
        for (int via = 0; via < n; via++) {
            if (start == via) {
                continue;
            }
            if (ans[start][via] == INT32_MAX || ans[via][start] == INT32_MAX) continue;
            res[start] = min(res[start], ans[start][via] + ans[via][start]);
        }
    }
    rep(i, n) { res[i] = min(res[i], slf[i]); }
    rep(i, n) {
        if (res[i] == INT32_MAX)
            cout << -1;
        else
            cout << res[i];
        cout << endl;
    }
    return 0;
}
