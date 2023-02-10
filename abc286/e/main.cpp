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

    vector<int> a(n);
    for (auto& ref : a) cin >> ref;
    vector<vector<int>> to(n);
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, n) {
            if (s[j] == 'N') continue;
            to[i].push_back(j);
        }
    }
    auto solve = [&](const int start, const int goal) -> void {
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq;
        pq.push({0, -a[start], start});
        vector<ll> memo(n, -1);
        memo[start] = start;
        int steps = -1;
        while (!pq.empty() && memo[goal] == -1) {
            ll step = pq.top()[0], cost = -pq.top()[1], cur = pq.top()[2];
            pq.pop();
            for (const int nxt : to[cur]) {
                if (memo[nxt] != -1) continue;
                memo[nxt] = cost + a[nxt];
                if (nxt == goal) steps = step + 1;
                pq.push({step + 1, -memo[nxt], nxt});
            }
        }
        if (memo[goal] == -1)
            puts("Impossible");
        else
            cout << steps << " " << memo[goal] << endl;
    };
    int q;
    cin >> q;
    rep(i, q) {
        int u, v;
        cin >> u >> v, u--, v--;
        solve(u, v);
    }

    return 0;
}
