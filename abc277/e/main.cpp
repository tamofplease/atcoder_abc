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

struct Data {
    int cur;
    bool available;
    int cost;
    Data(int cur, bool available, int cost) : cur(cur), available(available), cost(cost){};
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    set<int> s;
    vector<vector<int>> av(n), dis(n);
    rep(i, m) {
        int u, v, a;
        cin >> u >> v >> a, u--, v--;
        (a ? av : dis)[u].push_back(v);
        (a ? av : dis)[v].push_back(u);
    }
    rep(i, k) {
        int ss;
        cin >> ss, ss--;
        s.insert(ss);
    }

    set<pair<int, bool>> memo;
    memo.emplace(0, true);

    int ans = INT32_MAX;

    queue<Data> q;
    q.emplace(0, true, 0);

    function<void(int, bool, int)> memoized_push = [&](int val, bool available, int cost) {
        if (memo.count({val, available})) return;
        memo.emplace(val, available);
        q.emplace(val, available, cost);
    };

    while (q.size()) {
        const auto [cur, available, cost] = q.front();
        q.pop();

        if (cur == n - 1) {
            ans = min(ans, cost);
            continue;
        }

        for (int nxt : (available ? av : dis)[cur]) memoized_push(nxt, available, cost + 1);

        if (s.count(cur))
            for (int nxt : (available ? dis : av)[cur]) memoized_push(nxt, !available, cost + 1);
    }
    if (ans == INT32_MAX) {
        puts("-1");
    } else {
        cout << ans << endl;
    }

    return 0;
}
