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
    int m;
    cin >> m;
    vector<vector<int>> to(9);
    rep(i, m) {
        int u, v;
        cin >> u >> v, u--, v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    vector<int> v(9, 8);
    rep(i, 8) {
        int a;
        cin >> a, a--;
        v[a] = i;
    }
    int sp = 0;
    rep(i, 9) if (v[i] == 8) sp = i;
    set<vector<int>> been;
    queue<pair<pair<int, int>, vector<int>>> q;
    q.push({{0, sp}, v});
    int ans = -1;

    function<bool(vector<int>&)> isValid = [&](vector<int>& cur) -> bool {
        bool isValid = true;
        for (int i = 0; i < 9; i++)
            if (cur[i] != i) isValid = false;
        return isValid;
    };
    while (!q.empty()) {
        auto [info, cur] = q.front();
        auto [cost, space] = info;
        q.pop();
        if (isValid(cur)) {
            ans = cost;
            break;
        }
        for (int nxt : to[space]) {
            swap(cur[space], cur[nxt]);
            if (!been.count(cur)) {
                been.insert(cur);
                q.push({{cost + 1, nxt}, cur});
            }
            swap(cur[space], cur[nxt]);
        }
    }
    cout << ans << endl;

    return 0;
}
